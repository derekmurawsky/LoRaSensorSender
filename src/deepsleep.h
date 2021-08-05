#include "defines.h"
#include "esp_wifi.h"

// Configure wakeup sources
void configureWakeupSources() {
  // Configure the program button as a wakeup source
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, 0);
  // Configure a sleep timer as a wakeup source
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
}

void disableWifiBluetooth() {
  esp_wifi_stop();
  // WiFi.mode(WIFI_OFF);
  btStop();
}

void print_wakeup_reason(esp_sleep_wakeup_cause_t wakeup_reason) {
  switch (wakeup_reason) {
  case ESP_SLEEP_WAKEUP_EXT0:
    Serial.println("Wakeup caused by external signal using RTC_IO");
    break;
  case ESP_SLEEP_WAKEUP_EXT1:
    Serial.println("Wakeup caused by external signal using RTC_CNTL");
    break;
  case ESP_SLEEP_WAKEUP_TIMER:
    Serial.println("Wakeup caused by timer");
    break;
  case ESP_SLEEP_WAKEUP_TOUCHPAD:
    Serial.println("Wakeup caused by touchpad");
    break;
  case ESP_SLEEP_WAKEUP_ULP:
    Serial.println("Wakeup caused by ULP program");
    break;
  default:
    Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason);
    break;
  }
}