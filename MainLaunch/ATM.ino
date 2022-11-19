boolean initATM() {
  if(!bme.begin()){ return false; }
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
  return true;
}

void readATM() {
  if (bme.performReading()) {
    tempC = bme.temperature;
    pascals = (bme.pressure / 100.0); // hPa
    humidity = bme.humidity; // %
    gas = (bme.gas_resistance / 1000.0); // KOhms
    altm = bme.readAltitude(SEALEVELPRESSURE_HPA);
  }
  delay(10);
}
