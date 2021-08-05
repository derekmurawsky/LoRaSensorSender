#include "Adafruit_BME280.h"
#include "Adafruit_Sensor.h"
#include "ArduinoJson.h"
#include "Preferences.h"
#include "WiFi.h"
#include "Wire.h"
#include "deepsleep.h"
#include "defines.h"
#include "helpers.h"
#include "lorahelpers.h"
#include "screen.h"

String rssi = "RSSI --";
String packSize = "--";
String packet;
Preferences preferences;
String sensorID;
Adafruit_BME280 bme;
RTC_DATA_ATTR int bootCount = 0;

void setup() {
  ++bootCount;
  Serial.begin(115200);
  Wire1.begin(21, 22);
  while (!Serial) {
  }; // wait for serial
  Serial.println("Boot number: " + String(bootCount));
  print_wakeup_reason();
  preferences.begin("loranet", false);
  if (preferences.isKey("sensorID")) {
    sensorID = preferences.getString("sensorID", "");
  } else {
    sensorID = "default";
  }
  // Disable Wifi and Bluetooth for Battery savings
  WiFi.mode(WIFI_OFF);
  btStop();
  if (!bme.begin(BME280_ADD, &Wire1)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  } else {
    // Set sensors to low power mode and reduce sampling.
    bme.setSampling(bme.MODE_FORCED, bme.SAMPLING_X2, bme.SAMPLING_X2,
                    bme.SAMPLING_X2, bme.FILTER_OFF, bme.STANDBY_MS_500);
  }
  configureWakeupSources();
}

void loop() {
  displayInit();
  initLoRa(BAND, true);
  DynamicJsonDocument doc(128);
  // Get measurements
  bme.takeForcedMeasurement();
  measurements values(bme.readTemperature(), bme.readHumidity(),
                      bme.readPressure());

  // Build packet data
  doc["SID"] = sensorID;
  doc["BC"] = bootCount;
  doc["T"] = round_up(values.temperature, 2);
  doc["H"] = round_up(values.humidity, 2);
  doc["P"] = round_up(values.pressure, 2);

  // send packet
  LoRa.beginPacket();
  LoRa.setTxPower(14, RF_PACONFIG_PASELECT_PABOOST);
  serializeJson(doc, LoRa);
  LoRa.endPacket();

  // Send data via serial for debug
  Serial.println("Size of JSON doc: " + String(measureJson(doc)));
  Serial.println("Size of MessagePack doc: " + String(measureMsgPack(doc)));
  serializeJson(doc, Serial);
  Serial.println();

  // Display the data
  // displayMeasurements(values);
  displayMeasurements(values);
  Serial.println("Going to sleep now");
  delay(1000);
  Serial.flush();
  esp_deep_sleep_start();
  delay(SLEEP_TIME);
}
