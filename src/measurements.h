/**
 * @file measurements.h
 * @brief This file contains a simple data class to hold measurements
 * @date 2021-08-05
 */

/**
 * @brief A class to hold simple measurement data
 *
 */
class measurements {
public:
  float temperature, humidity, pressure;

  /**
   * @brief Construct a new measurements object
   *
   * @param T Temperature
   * @param H Humidity
   * @param P Pressure
   */
  measurements(float T, float H, float P) {
    temperature = T;
    humidity = H;
    pressure = P;
  }
};