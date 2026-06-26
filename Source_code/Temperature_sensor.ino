/*
  Project: ESP32 Wi-Fi Temperature and Humdity Monitor
  Description:
  Reads temperature and humidity from a DHT11 sensor,
  displays the values on a 16x2 I2C LCD screen, and hosts a
  local webpage on the ESP32 to show live readings.

  Hardware:
  - ESP32
  - DHT11 sensor
  - 16x2 I2C LCD
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>
#include <WiFi.h>
#include <WebServer.h>

// DTH11 sensor pin config and sensor type
#define DHTPIN 4
#define Type DHT11

// Create sensor, LCD, and web server objects
DHT HT(DHTPIN, Type);

// Variables to store live sensor readings
float humidity;
float tempC;
LiquidCrystal_I2C lcd(0x27, 16 ,2);

// Wi-Fi credentials
const char* ssid = "your WiFi name";
const char* password = "your password";
WebServer server(80);

// Generate and send the webpage showing live temperature and humidity
void displayTemp() {

  String page =
  "<meta http-equiv=\"refresh\" content=\"1\">"
  "<html><body style='height:100vh;display:flex;flex-direction:column;"
  "justify-content:center;align-items:center;font-family:Arial;'>"
  "<h1 style='font-size:60px;'>Temperature and Humidity</h1>"
  "<p style='font-size:32px;'>Temperature: " + String(tempC,1) + "&deg;C</p>"
  "<p style='font-size:32px;'>Humidity: " + String(humidity,1) + "%</p>"
  "</body></html>";
  
  server.send(200, "text/html", page);
}

void setup() {
  // Initialize serial monitor, sensor, and LCD
  Serial.begin(115200);
  HT.begin();
  lcd.init();
  lcd.backlight();

  // Connect ESP32 to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.print("ESP32 IP Address: ");

  // Start web server
  Serial.println(WiFi.localIP());
  server.on("/",displayTemp);
  server.begin();
  Serial.print("Web server started");
}

void loop() {
  // Read sensor values
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();

  // Show readings on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.write(0xDF);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);

  // Handle incoming browser requests
  server.handleClient();
}
