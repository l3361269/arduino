#include <SoftwareSerial.h>   // 引用程式庫
 int time1=0;
 int time2=0;
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數
 
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
 
  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
}
 
void loop() {
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
 time1=millis();
 if(time1-time2<=100)
 { 
  
     Serial.println(voltage);
     // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  if (Serial.available()) {
   // val = Serial.read();
    BT.println(Serial.read());
  }
 /*
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    //val = BT.read();
    Serial.println(voltage);
  }*/
 }
 time2=time1;
  
}
