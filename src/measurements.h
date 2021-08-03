/* Simple class to handle measurements */

class measurements {
public:
  float temperature, humidity, pressure;

  measurements(float T, float H, float P) {
    temperature = T;
    humidity = H;
    pressure = P;
  }
};