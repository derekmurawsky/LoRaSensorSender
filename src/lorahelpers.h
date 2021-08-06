/**
 * @file lorahelpers.h
 * @brief Lora initializer
 * @date 2021-08-05
 */

#include "SPI.h"
#include "lora/LoRa.h"

/**
 * @brief Initializes LoRa radio
 * This function was pulled out of the Heltec library to allow finer grained
 * control of what was initialized when
 * @param band The band to be used
 * @param paboost Turns the power of the transmitter to maximum
 */
void initLoRa(long band, bool paboost) {
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST_LoRa, DIO0);
  if (!LoRa.begin(band, paboost)) {
    Serial.println("There was an issue initializing the LoRa radio.");
  };
}