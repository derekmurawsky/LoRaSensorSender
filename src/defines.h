/*
This file is for #defines that are used throughout the project
*/

#define BAND 915E6 // you can set band here directly,e.g. 868E6,915E6
#define SEALEVELPRESSURE_HPA                                                   \
  (1013.25) /* Sealevel pressure, used to roughly calculate altitude */
#define BME280_ADD 0x76 /* The address of the BME sensor */
#define uS_TO_S_FACTOR                                                         \
  1000000                /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 30 /* Time ESP32 will go to sleep for (in seconds) */