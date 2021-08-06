/**
 * @file screen.h
 * @brief Screen related helper functions
 * Many bits of this code were pulled from the Heltec library
 */
#include "defines.h"
#include "measurements.h"
#include "oled/SSD1306Wire.h"

SSD1306Wire *display; /* The OLED display object */

/**
 * @brief Powers up and initializes the OLED display
 * This function powers up the display, flips it vertically, and sets the font
 * (ArialMT, plain, 10pt)
 */
void displayInit() {
  display =
      new SSD1306Wire(0x3c, SDA_OLED, SCL_OLED, RST_OLED, GEOMETRY_128_64);
  display->init();
  display->flipScreenVertically();
  display->setFont(ArialMT_Plain_10);
  display->display();
}
/**
 * @brief Displays a measurement object on the screen
 *
 * @param M measurement object to display
 */
void displayMeasurements(measurements M) {
  display->clear();
  display->drawString(0, 0, String("Temperature: " + String(M.temperature)));
  display->drawString(0, 12, "Humidity: " + String(M.humidity));
  display->drawString(0, 24, "Pressure: " + String(M.pressure));
  display->display();
}
