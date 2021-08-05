#include "defines.h"
#include "measurements.h"
#include "oled/SSD1306Wire.h"

SSD1306Wire *display;

/* boarInit() replaces Heltec.h and allows for finer grained control
 */
void displayInit() {
  display =
      new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);
  display->init();
  display->flipScreenVertically();
  display->setFont(ArialMT_Plain_10);
  display->display();
}

void screenInit() {
  display->init();
  display->flipScreenVertically();
  display->setFont(ArialMT_Plain_10);
  display->display();
}

void displayMeasurements(measurements M) {
  display->clear();
  display->drawString(0, 0, String("Temperature: " + String(M.temperature)));
  display->drawString(0, 12, "Humidity: " + String(M.humidity));
  display->drawString(0, 24, "Pressure: " + String(M.pressure));
  display->display();
}
