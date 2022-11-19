#include <Wire.h>               //OLED/LUX
#include <SPI.h>                //SD/ATM
#include <SD.h>                 //SD
#include <TinyGPS++.h>          //GPS
#include <Adafruit_SSD1306.h>   //OLED
#include <Adafruit_Sensor.h>    //ATM/LUX
#include <Adafruit_BME680.h>    //ATM
#include "Adafruit_TSL2591.h"   //LUX

//=====================================
//ATM =================================
#define SEALEVELPRESSURE_HPA (1013.2)
#define BME_SCK 40
#define BME_MISO 41
#define BME_MOSI 42
#define BME_CS 43
Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

//ATM variables =======================
float pascals;
float altm;
float humidity;
float gas;
float tempC;

//=====================================
//LUX =================================
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

//LUX variables =======================
uint32_t lum;
int16_t ir, full;
float lux;

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

//SD Card ==================================
#define chipSelect 53

void setup() {
  //Serial
  Serial.begin(115200); //Computer
  Serial1.begin(9600); //GPS
  sanity();
}

void loop() {
  // put your main code here, to run repeatedly:
  String data = mkdata();
  Serial.println(data);
  writeSD(data);
  delay(100);
}
