/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const byte x = B10101010;
int state;
void setup() {
  int state=0;

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
//  Serial.write(Serial.print(170, HEX));
}

void loop() { // run over and over
   if (state==0) {
       if (Serial.read()=='a'||Serial.read()=='A') {
       mySerial.write('S1');
       state=1;}
       if(Serial.read()=='r'||Serial.read()=='R') {
                          mySerial.write("S0");
                          state=0;}
       
   }
   if (state==1) {
               if (Serial.read()=='a'||Serial.read()=='A') {
                          mySerial.write("S2");
                          state=2;}
                          if(Serial.read()=='r'||Serial.read()=='R') {
                          mySerial.write("S0");
                          state=0;}
   }
    if (state==2) {
               if (Serial.read()=='a'||Serial.read()=='A') {
                          mySerial.write("S2");
                          state=2;}
               if(Serial.read()=='b'||Serial.read()=='B'){
                         mySerial.write("S1");
                         state=1;}
               if(Serial.read()=='c'||Serial.read()=='C'){
                        mySerial.write("S4");
                        state=4;}
       if(Serial.read()=='r'||Serial.read()=='R') {
                          mySerial.write("S0");
                          state=0;}
    }
     if (state==4) {
               if (Serial.read()=='d'||Serial.read()=='D') {
                          mySerial.write("S3");
                          state=3;}
                          if(Serial.read()=='r'||Serial.read()=='R') {
                          mySerial.write("S0");
                          state=0;}
   }
    if(state==3) {
               if (Serial.read()=='a'||Serial.read()=='A') {
                          mySerial.write("S1");
                          state=1;}
                          if(Serial.read()=='b'||Serial.read()=='B') {
                          mySerial.write("S4");
                          state=4;}
                          if(Serial.read()=='r'||Serial.read()=='R') {
                          mySerial.write("S0");
                          state=0;}
   }
             
}
 
