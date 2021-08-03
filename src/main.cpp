#include "Adafruit_BME280.h"
#include "Adafruit_Sensor.h"
#include "ArduinoJson.h"
#include "Preferences.h"
#include "WiFi.h"
#include "Wire.h"
#include "defines.h"
#include "screen.h"

unsigned int counter = 0;
String rssi = "RSSI --";
String packSize = "--";
String packet;
Preferences preferences;
String sensorID;
Adafruit_BME280 bme;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ; // time to get serial running
  Heltec.begin(
      true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/,
      true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  preferences.begin("loranet", false);
  sensorID = preferences.getString("sensorID", "");
  if (sensorID == "") {
    sensorID = "default";
  }
  // Disable Wifi and Bluetooth for Battery savings
  WiFi.mode(WIFI_OFF);
  btStop();
  screenInit();
  delay(1500);
  if (!bme.begin(BME280_ADD)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }
  // Set sensors to low power mode and reduce sampling.
  bme.setSampling(bme.MODE_FORCED, bme.SAMPLING_X2, bme.SAMPLING_X2,
                  bme.SAMPLING_X2, bme.FILTER_OFF, bme.STANDBY_MS_500);
}

void loop() {
  Heltec.display->clear();
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  Heltec.display->setFont(ArialMT_Plain_10);

  Heltec.display->drawString(0, 0, "Sending packet: ");
  Heltec.display->drawString(90, 0, String(counter));
  Heltec.display->display();
  DynamicJsonDocument doc(128);
  // Get measurements
  bme.takeForcedMeasurement();
  measurements values(bme.readTemperature(), bme.readHumidity(),
                      bme.readPressure());

  // Build packet data
  doc["sensorID"] = sensorID;
  doc["count"] = counter;
  doc["temperature"] = values.temperature;
  doc["humidity"] = values.humidity;
  doc["pressure"] = values.pressure;

  // send packet
  LoRa.beginPacket();
  LoRa.setTxPower(14, RF_PACONFIG_PASELECT_PABOOST);
  serializeJson(doc, LoRa);
  LoRa.endPacket();

  // Send data via serial for debug
  serializeJson(doc, Serial);
  Serial.println();

  // Display the data
  displayMeasurements(values);
  counter++;
  delay(SLEEP_TIME);
}
