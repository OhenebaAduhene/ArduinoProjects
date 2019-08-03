#include <Wire.h>
#define uchar unsigned char
uchar data[16];
int t = 0;
void setup() {
  // put your setup code here, to run once:
//  Wire.begin();
  Serial.begin(9600);
  pinMode(0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  Wire.requestFrom(9,16);
//  while(Wire.available()){
//    data[t] = Wire.read();
//    if(t<15)
//      t++;
//    else{
//      t=0;
//      Serial.println((char*)data);
//      break;
//    }
//}

}
