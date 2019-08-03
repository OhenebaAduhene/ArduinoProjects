#include <Wire.h>
#define uchar unsigned char
uchar t;
//void send_data(short a1,short b1,short c1,short d1,short e1,short f1);
uchar data[16];
void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  t = 0;
}
void loop()
{
  Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }

if ((data[0] && data[2] > 15) && (data[12] && data[14] > 15)){
  Serial.print("No black detected \n");
  Serial.print("We can move forward \n");
  delay(3000);
  
}
else{
  Serial.print("We cant move forward \n");
  if(data[0] && data[2] < 15){
    Serial.print("Moving in data 1 and 0's direction \n");
  }

   if(data[12] && data[14] < 15){
    Serial.print("Moving in data 12 and 14's direction \n");
  }
  
  delay(3000);
}
}
