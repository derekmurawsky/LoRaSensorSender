#include "defines.h"
#include "esp_wifi.h"

/*
 * Configure wakeup sources
 *
 * This configures wakeup sources for the board.
 *  * GPIO_NUM_0 (the prg button)
 *  * A timer (TIME_TO_SLEEP) - Note: This is in seconds
 */
void configureWakeupSources() {
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, 0);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
}

/*
 * Disable WiFi and Bluetooth
 */
void disableWifiBluetooth() {
  esp_wifi_stop();
  // WiFi.mode(WIFI_OFF);
  btStop();
}

/*
 * Prints the reason the board woke up to the serial console
 * @param[in] wakeup_reason The sp_sleep_wakeup_cause_t as returned by
 * esp_sleep_get_wakeup_cause()
 */
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