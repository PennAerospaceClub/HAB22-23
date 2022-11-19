void writeSD(String dataString){
  File dataFile = SD.open("datalog.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
}

String mkdata(){
  String data = 
  //Times
  String(gpstime) + "," + 
  String(gpsdate) + "," + 
  String(millis()) + "," + 
  //GPS
  String(latit, 6) + "," + 
  String(longit, 6) + "," + 
  String(alt, 6) + "," + 
  String(course, 2) + "," + 
  String(speed, 2) + "," + 
  String(numsats) + "," + 
  String(velDiff, 3) + "," + 
  //ATM data
  String(pascals, 4) + "," +
  String(humidity, 2) + "," +
  String(gas, 2) + "," +
  String(altm, 2) + "," +
  String(tempC, 2) + "," +
  //LUX data
  String(lum, 4) + "," +
  String(ir, 4) + "," +
  String(lux, 4);
  
  return data;
}
