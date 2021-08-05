#include "SPI.h"
#include "lora/LoRa.h"

void initLoRa(long band, bool paboost) {
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST_LoRa, DIO0);
  if (!LoRa.begin(band, paboost)) {
  };
}