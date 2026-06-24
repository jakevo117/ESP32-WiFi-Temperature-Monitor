# ESP32 WiFi Temperature Monitor

## Overview
### This project showcase a temperature and humidity monitoring system which was built using ESP32 using a DTH11 sensor and a 16x2 I2C LCD screen. The results obtained by the sensor are are displayed on both the LCD screen and a local webpage hosted by the ESP32 through WiFi. 
### The goal of this project is to learn about sensor interfacing, I2C communication and embedded webserver as well as knowledge about the ESP32 specifically and microcontroller in general.

## Features
- Real-time temperature and humidity monitoring
- Sensor readings displayed on a 16x2 I2C LCD
- Local web page hosted by the ESP32 using WiFi
- Automatic webpage refresh every 1 second
- Built and programmed using Arduino IDE

## Components Used
- ESP32 microcontroller and extension board
- DHT11 temperature and humidity sensor
- 16x2 I2C LCD
- Breadboard
- Jumper wires
- 10kΩ resistor
- USB cable for programming and power

## Circuit Connections
### DHT11 to ESP32
- VCC -> 3.3V
- GND -> GND
- DATA -> GPIO 4
- Pull-up resistor connected between DATA and VCC

### I2C LCD to ESP32
- VCC -> 5V 
- GND -> GND
- SDA -> GPIO 21
- SCK -> GPIO 22

## How It Works
The DHT11 sensor measures the temperature and humidity of the surrouding environment. The ESP32 reads the data and process the value in the program. Next, the reading will be displayed on the LCD screen for monitoring and sent to a webpage hosted by the ESP32 via WiFi. When the ESP32 is successfully connected to the WiFi, it will print thelocal IP address to the Serial Monitor, which can be used to access the local webpage and monitor the temparature and humidity results. The webpage is refreshed every 1 second to keep the results up-to-date.

## Results
The project successfully displayed live temperature and humidity readings on both the LCD and a browser-based interface.

Completed outputs:
- Working ESP32 and DHT11 hardware setup
- LCD display with live sensor values
- Local Wi-Fi webpage showing temperature and humidity
- Automatic webpage refresh for near real-time monitoring

## Challenges and Learning
Through this project, I learned how to:
- Use a DHT11 sensor with the ESP32 to obtain the temperature and humidity
- Utilize I2C communication with a 16x2 LCD
- Configure the ESP32 to connect to a Wi-Fi network
- Build a simple embedded web server using Arduino IDE
- Combine hardware sensor with browser-based monitoring
- Debug wiring, program and pin mapping

## Future Improvements
- Add temperature status labels such as Cold, Normal, and Hot
- Add an LED or buzzer alert for high temperature
- Improve webpage styling and layout using HTML or CSS
- Log sensor data over time
- Expand the project into a smart room monitoring system
