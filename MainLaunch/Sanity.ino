  void sanity() {
  //========================================
  //Sanity Declarations ====================
  static boolean sd = false;
  static boolean atm = false;
  static boolean gps_attached = false;
  static boolean lux_attached = false;

  if (!sd) {
    if (SD.begin(chipSelect)) {
      sd = true;
      Serial.println("sd card began");
    }
  }

  if (!lux_attached) {
    if (initLux()) {
      lux_attached = true;
    }
  }
  
  if (!atm) {
    if (initATM()) {
      atm = true;
    }
  }

  //GPS
  if (!gps_attached) {
    gps_attached = true;
  }

  //========================================
  //Data Verification ======================
  if (gps_attached) {
    Serial.println("GPS attached");
    readGPS();
  }
  if (atm) {
    Serial.println("atm attached");
    readATM();
  }

  if(lux_attached) {
    Serial.println("lux attached");
    readLux();
  }

  if(sd) {
    Serial.println("sd attached");
    String data = mkdata();
    Serial.println(data);
    writeSD(data);
  }
  
}

 void updateSensors() {
    readGPS();
    readATM();
    readLux();
}
