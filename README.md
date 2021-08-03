# Heltec WiFi Lora32 v2 Remote Temperature Sensor

This is a simple sensor project based on the [Heltec Wifi Lora 32 v2](https://heltec.org/project/wifi-lora-32/) and a [BME280](https://www.amazon.com/Organizer-Temperature-Humidity-Atmospheric-Barometric/dp/B07V5CL3L8/).

I wanted to learn about LoRa and low power sensors and this is the first project on that path. I have a small homestead and wanted to monitor the temperature, pressure, humidity, and possibly light levels in my animal enclosures. The first prototype will go in my chicken coop and run.

Eventually I want to extend this project to support different sensors including soil moisture for our gardens and a general purpose weather station.

## ToDos

* [ ] Clean up the codebase and figure out better ways of handling the objects and files. (I'm new to cpp as well...)
* [ ] Deep sleep mode, with waking every X interval for data send
* [ ] Wake on button press to send data and display current data on the screen
* [ ] Support an ambient light sensor with the same codebase. Can this be made pluggable?

## Relevant Links

* [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library) and [Example](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test)
* [ArduinoJSON](https://arduinojson.org/)
* [Heltec ESP32 Library](https://github.com/HelTecAutomation/Heltec_ESP32)
* [Heltec Wifi LoRa 32 v2 pinout diagram](assets/WIFI_LoRa_32_V2.pdf)
* [PlatformIO](https://platformio.org/) (Via [VSCode](https://code.visualstudio.com/))
