// 定義腳位
#define PIN_a1 13
#define PIN_b1 A5
#define PIN_c1 A4
#define PIN_d1 A3
#define PIN_e1 A2
#define PIN_f1 A0
#define PIN_g1 A1
#define PIN_a2 4
#define PIN_b2 5
#define PIN_c2 7
#define PIN_d2 8
#define PIN_e2 9
#define PIN_f2 10
#define PIN_g2 6
#define PIN_2 2
#define PIN_3 3

#define SEG_NUM 7

//const byte seg_pins[SEG_NUM] = {PIN_a, PIN_b, PIN_c, PIN_d, PIN_e, PIN_f, PIN_g, PIN_h};
const byte ledPin_X[SEG_NUM]={PIN_a1,PIN_b1,PIN_c1, PIN_d1, PIN_e1, PIN_f1, PIN_g1};
const byte ledPin_Y[SEG_NUM]={PIN_a2,PIN_b2,PIN_c2, PIN_d2, PIN_e2, PIN_f2, PIN_g2};

#define t true
#define f false
const boolean data[10][SEG_NUM] = {
  {t, t, t, t, t, t, f}, // 0
  {f, t, t, f, f, f, f}, // 1
  {t, t, f, t, t, f, t}, // 2
  {t, t, t, t, f, f, t}, // 3
  {f, t, t, f, f, t, t}, // 4
  {t, f, t, t, f, t, t}, // 5
  {t, f, t, t, t, t, t}, // 6
  {t, t, t, f, f, f, f}, // 7
  {t, t, t, t, t, t, t}, // 8
  {t, t, t, t, f, t, t}, // 9
};
const long interval=1000; //1000ms
volatile unsigned long previous_time=0; //是顯示出來的時間
volatile unsigned long difference_time=0; //是為了讓current_time和previous_time相差一秒
volatile unsigned long current_time;//裝millis()的
volatile boolean state_clear=0; //記錄當下有沒有clear
volatile boolean state_stop=0; //記錄當下有沒有stop
volatile boolean state_start=0; //記錄當下有沒有start

//clear的ISR
void reset(){ 
  if(state_clear==0)
  {
   previous_time=0;
   state_clear=1;
   for(int i=0;i<7;i++)
    {
      digitalWrite(ledPin_X[i],data[0][i]==t?HIGH:LOW);
      
      digitalWrite(ledPin_Y[i],data[0][i]==t?HIGH:LOW);
    }
    Serial.println("clear");
  }
   }

//stop跟start的ISR
void stop(){
  if(state_stop==0&state_clear==0) 
  {
  state_stop=1;
  Serial.println("stop");
  } 
  else
  {
  state_start=1;
  Serial.println("start");
  }
}

void setup() {
  for(int i=0;i<7;i++)
  {
    pinMode(ledPin_X[i],OUTPUT);
    pinMode(ledPin_Y[i],OUTPUT);
  }
  pinMode(PIN_2,INPUT_PULLUP);
  pinMode(PIN_3,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_2),reset,FALLING);
  attachInterrupt(digitalPinToInterrupt(PIN_3),stop,FALLING);

  for(int i=0;i<7;i++)
    {
      digitalWrite(ledPin_X[i],data[0][i]==t?HIGH:LOW);
      
      digitalWrite(ledPin_Y[i],data[0][i]==t?HIGH:LOW);
     }

  Serial.begin(115200);

}

void loop() {
  current_time=millis();

  if(state_clear==1)
  {
    if(state_start==1)
    {
      difference_time=current_time;
      state_clear=0;
      state_stop=0;
      state_start=0;
    }
  }
  if(state_stop==1)
  {
    if(state_start==1)
    {
      difference_time=current_time;
      state_stop=0;
      state_clear=0;
      state_start=0;
    }
  }
   if(state_clear==0&state_stop==0)
   {
    if(current_time-difference_time>=interval) 
    {
      difference_time=millis();
      previous_time+=1;
      Serial.println(previous_time);
      int x=previous_time/10;
      int y=previous_time%10;
      for(int i=0;i<7;i++)
      {
        digitalWrite(ledPin_Y[i],data[x][i]==t?HIGH:LOW);
        Serial.println(x);
        digitalWrite(ledPin_X[i],data[y][i]==t?HIGH:LOW);
        Serial.println(y);
      }
    }
   }
}
