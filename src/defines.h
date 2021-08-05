/*
This file is for #defines that are used throughout the project
*/

#define BAND 915E6 // you can set band here directly,e.g. 868E6,915E6
#define SEALEVELPRESSURE_HPA (1013.25)
#define BME280_ADD 0x76
#define SLEEP_TIME 30000
#define uS_TO_S_FACTOR                                                         \
  1000000                /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 30 /* Time ESP32 will go to sleep (in seconds) */