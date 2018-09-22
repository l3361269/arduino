/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout 
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
//#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
//#define BMP_SCK 13
//#define BMP_MISO 12
//#define BMP_MOSI 11 
//#define BMP_CS 10

Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
float n=0;
  float time1=0;
  float time2=0;
void setup() {
  
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  
  if (!bmp.begin()) {  
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}
void loop() {
  time1=millis();
  if(time2!=time1){
    n=time1-time2;
    //Serial.println(n/1000);
    Serial.println(n/1000);
     //Serial.print(F("Pressure = "));
    Serial.println(bmp.readPressure());
   // Serial.println(" Pa");
    
    //mySerial.println();
    //mySerial.print(F("Pressure = "));
    //mySerial.print(bmp.readPressure());
    //mySerial.println(" Pa");
    
  }
  time2=time1;
}
