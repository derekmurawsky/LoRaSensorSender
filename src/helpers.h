/*
 * This file is used to store small helper functions that don't have another
 * place to call home.
 */

#include "cmath"

/*
 * @brief Function to round up a float to a certain number of decimal places
 * @param value The float that you want to round up
 * @param decimal_places The number of decimal places you want
 * @see
 * https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places
 */
double round_up(float value, int decimal_places) {
  const double multiplier = std::pow(10.0, decimal_places);
  return std::ceil(value * multiplier) / multiplier;
}