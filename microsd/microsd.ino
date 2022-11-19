#include <SD.h>                 //SD
String dataString;
void setup() {
  // put your setup code here, to run once:
  dataString = "";
}

void writeSD(String dataString){
  File dataFile = SD.open("datalog.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
}

String mkdata() {
  String dataStr = 
  String(millis()) + "," + "test";
  return dataStr;
}

void loop() {
  // put your main code here, to run repeatedly:
  writeSD(mkdata());
  delay(3000);
}
