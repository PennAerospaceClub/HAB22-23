#include <TinyGPSPlus.h>
#include <TinyGPS++.h>
 TinyGPSPlus gps;
double latit;   //degrees
double longit;  //degrees
double alt;     //meters
double alto;
double velDiff;
double vel[] = {0, 0, 0, 0, 0}; //meters
long gpstime;   //HHMMSSCC
long gpsdate;   //DDMMYY
int numsats;
double course;  //degrees
double speed;   //mph
 void setup() {
Serial.begin(115200);
Serial1.begin(9600);
}
void loop() {
  readGPS();
  Serial.println(mkdata());
  }
void readGPS(){
 smartDelay(400);
 if(gps.location.isValid()){ 
  latit = gps.location.lat(); longit = gps.location.lng(); }
 if(gps.altitude.isValid()){ 
    alto = alt;
    alt = gps.altitude.meters(); 

    double currvel = (alt - alto);
    vel[0] = vel[1]; vel[1] = vel[2]; vel[2] = vel[3]; vel[3] = vel[4]; vel[4] = currvel;
    velDiff = (vel[0] + vel[1] + vel[2] + vel[3] + vel[4])/5;
 }
 if(gps.time.isValid()){ gpstime = gps.time.value(); }
 if(gps.date.isValid()){ gpsdate = gps.date.value(); }
 if(gps.satellites.isValid()){ numsats = gps.satellites.value(); }
 if(gps.course.isValid()){ course = gps.course.deg(); }
 if(gps.speed.isValid()){ speed = gps.speed.mph(); }
 delay(10);
}

static void smartDelay(unsigned long ms){
  unsigned long start = millis();
  do 
  {
    while (Serial1.available() && (!gps.altitude.isUpdated()) ) {
      gps.encode(Serial1.read()); 
    }
  } 
  
  while (millis() - start < ms);
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
  String(velDiff, 3);
  return data;
}
