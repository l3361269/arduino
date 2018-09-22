const int in_PinA=2;
const int in_PinB=3;
const int in_PinC=4;
const int out_PinS=5;
const int out_PinC=6;

int buttonState_A=0;
int buttonState_B=0;
int buttonState_C=0;

void setup() {
  pinMode(in_PinA,INPUT);
  pinMode(in_PinB,INPUT);
  pinMode(in_PinC,INPUT);
  pinMode(out_PinS,OUTPUT);
  pinMode(out_PinC,OUTPUT);

  Serial.begin(115200);
}

void loop() {
  buttonState_A=digitalRead(in_PinA);
  buttonState_B=digitalRead(in_PinB);
  buttonState_C=digitalRead(in_PinC);

  Serial.println(buttonState_A);
  Serial.println(buttonState_B);
  Serial.println(buttonState_C);
  

 /* if((buttonState_A&buttonState_B)==1)
  {
    Serial.println("S on");
    digitalWrite(out_PinS,HIGH);
  }
  else
  {
    digitalWrite(out_PinS,LOW);
    Serial.println("S off");
  }
  if((buttonState_A^buttonState_C)==1)
  {
    digitalWrite(out_PinC,HIGH);
    Serial.println("C on");
  }
  else
  {
    digitalWrite(out_PinC,LOW);
    Serial.println("C off");
  }
  */

  //S
  /*if((buttonState_A^buttonState_B)^buttonState_C)
  {
    Serial.println("S high");
   digitalWrite(out_PinS,HIGH); 
  }
  else{
    Serial.println("S low");
    digitalWrite(out_PinS,LOW);
  }
  //C
  if((buttonState_A&buttonState_B)|((buttonState_A^buttonState_B)&buttonState_C))
  {
    Serial.begin("C high");
    digitalWrite(out_PinC,HIGH);
  }
  else
  {
    Serial.println("C low");
    digitalWrite(out_PinC,LOW);
  }
*/
}
