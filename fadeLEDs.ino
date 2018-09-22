#define NUM 6
#define NEXT 180

int leds[NUM]={3,5,6,9,10,11};
int brightness[NUM];
int i;
int set_br(int leds,int br)
{
  analogWrite(leds,br);
  br-=5;
  if(br<0) br=0;
  return br;
}

void setup() {
  for(i=0;i<NUM;i++){
     pinMode(leds,OUTPUT);
  }
}

void loop() {
  for(i=0;i<NUM;i++){
   brightness[i]=255;
  }
  i=0;
  while(brightness[5]>254)
  {
    brightness[i]=set_br(leds[i],brightness[i]);
    if(i>0) brightness[i-1]=set_br(leds[i-1],brightness[i-1]);
    if(i>1) brightness[i-2]=set_br(leds[i-2],brightness[i-2]);
    if(i>2) brightness[i-3]=set_br(leds[i-3],brightness[i-3]);
    if(i>3) brightness[i-4]=set_br(leds[i-4],brightness[i-4]);
    if(i>4) brightness[i-5]=set_br(leds[i-5],brightness[i-5]);
    if(brightness[i]==NEXT) i++;
    delay(30);  
  }
  for(int i=0;i<NUM;i++)
  {
    brightness[i]=255;
  }
  i=5;
  while(brightness[0]>254){
    brightness[i]=set_br(leds[i],brightness[i]);
    if(i<5) brightness[i+1]=set_br(leds[i+1],brightness[i+1]);
    if(i<4) brightness[i+2]=set_br(leds[i+2],brightness[i+2]);
    if(i<3) brightness[i+3]=set_br(leds[i+3],brightness[i+3]);
    if(i<2) brightness[i+4]=set_br(leds[i+4],brightness[i+4]);
    if(i<1) brightness[i+5]=set_br(leds[i+5],brightness[i+5]);
    if(brightness[i]==NEXT) i--;
    delay(30);
  }

}
