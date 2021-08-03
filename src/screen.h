#include "defines.h"
#include "heltec.h"
#include "images.h"
#include "measurements.h"

void logo() {
  Heltec.display->clear();
  Heltec.display->drawXbm(0, 5, logo_width, logo_height, logo_bits);
  Heltec.display->display();
}

void screenInit() {
  Heltec.display->init();
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
  logo();
  delay(1500);
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "Heltec.LoRa Initialized successfuly!");
  Heltec.display->display();
}

void displayMeasurements(measurements M) {
  Heltec.display->clear();
  Heltec.display->drawString(0, 0,
                             String("Temperature: " + String(M.temperature)));
  Heltec.display->drawString(0, 12, "Humidity: " + String(M.humidity));
  Heltec.display->drawString(0, 24, "Pressure: " + String(M.pressure));
  Heltec.display->display();
}