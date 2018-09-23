#include <SoftwareSerial.h>
#include "HX711.h"
int time1 = 0; //提醒每小時
int time2 = 0;
int x=0;
int weight1 = 0; //差多少
int weight2 = 0;
int weight3 = 0; //總告多少
int water = 0; //次數
float s = 0;
float total = 0;
#define LED_BUILTIN A5
SoftwareSerial BT(2, 1); // 接收腳, 傳送腳

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Init_Hx711();				//初始化HX711模組連接的IO設置

  Serial.begin(9600);
  Serial.print("Welcome to use!\n");
  Get_Maopi();		//獲取毛皮
  delay(1000);
  Get_Maopi();		//獲取毛皮
  Serial.print("Start!\n");
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
void loop()
{
  x=Get_Weight();
  if(x>100){
     weight1 = x;
  }
 
  
  Serial.print("weight1=");
  Serial.println(weight1);
  
  delay(3000);

  time1 = millis();
  if (time1 - time2 >= 10000) //3600000
  { digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("給我喝水");
    if (Serial.available()) {
      BT.println("給我喝水");
    } time2 = time1;
  }

  if (weight2 - weight1 >= 10)
  { digitalWrite(LED_BUILTIN, LOW);
    /*if(weight3!=0){
      if(weight3>weight2){
        s=(weight3-weight2)/1000;//單次喝水量
        water+=1;
        total+=s;
        weight3=weight2;*/
    s = (weight2 - weight1); //單次喝水量
    water += 1;
    total += s;
    Serial.print("這次喝了");
    Serial.print(s);
    Serial.println("g");
    Serial.print("今天總共喝了");
    Serial.print(total);
    Serial.println("g");
    Serial.print("今天喝了");
    Serial.print(water);
    Serial.println("次");
    if (Serial.available()) {
      BT.print("這次喝了");
      BT.print(s);
      BT.println("g");
      BT.print("今天總共喝了");
      BT.print(total);
      BT.println("g");
      BT.print("今天喝了");
      BT.print(water);
      BT.println("次");
    }

  }

  weight2 = weight1;
}
