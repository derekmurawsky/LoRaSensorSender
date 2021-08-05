#include "cmath"
// from
// https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places
double round_up(float value, int decimal_places) {
  const double multiplier = std::pow(10.0, decimal_places);
  return std::ceil(value * multiplier) / multiplier;
}