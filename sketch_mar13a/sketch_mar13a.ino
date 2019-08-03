#include <L298N.h>
#include <Wire.h>
#define uchar unsigned char
//pin definition
#define ENA 9
#define IN1 8
#define IN2 7

#define ENB 6
#define IN3 5
#define IN4 4

//create a motor instance
L298N motor_L(ENA, IN1, IN2);
L298N motor_R(ENB, IN3, IN4);
int SPEED = 150;
int delaySpeed = 20;
int prev = -1;
uchar t;
uchar data[16];

int find_min_index(){
 int i=0;
 int min_index=0;
 int min_val = 9999;
 int SUM = 0;
 int MAX = 0;
 for(;i<8;i++){
  SUM += data[i*2];
  if(data[i*2]<min_val){
//      Serial.println(i);
      min_index = i;
      min_val = data[i*2];
    }
   if(data[i*2]>MAX){
      MAX = data[i*2];
    }
  }
//  Serial.print("Average : ");
//  Serial.println(SUM/8);
//  Serial.print("MAX : ");
//  Serial.println(MAX);
  if((MAX-(int)SUM/8)<10){
    return -1;
    }
  return min_index;
}

void setup() {

  //used for display information
  Serial.begin(9600);
  Wire.begin();
//  motor_R.setSpeed(0); // an integer between 0 and 255
//  motor_L.setSpeed(0);
//  motor_R.forward();
//  motor_L.forward();

}
int state = 1;
void loop() {
  
  while(1){
    Serial.println("LOOP");

//  READ FROM LINE FOLLOWER TO SET STATE
   Wire.requestFrom(9, 16);    // request 16 bytes from slave device #9
  while (Wire.available())   // slave may send less than requested
  {
    data[t] = Wire.read(); // receive a byte as character
    if (t < 15)
      t++;
    else
      t = 0;
  }
  int min_index = find_min_index();
  Serial.println(min_index);
  if(prev == min_index){
    }else{
    prev = min_index;
    switch(min_index){
      case 0:
        state = 2;
      break;
      case 1:
        state = 2;
      break;
      case 2:
        state = 1;
      break;
      case 3:
        state = 1;
      break;
      case 4:
        state = 1;
      break;
      case 5:
        state = 1;
      break;
      case 6:
        state = 3;
      break;
      case 7:
        state = 3;
      break;
      case -1:
        state = 0;
      break;
      }
    }

    
    switch(state){
    case 0:// STOP
        Serial.println("State 0");
        motor_R.stop();
        motor_L.stop();
    break;
    case 1:// FORWARD
        Serial.println("State 1");
        motor_R.setSpeed(SPEED);
        motor_L.setSpeed(SPEED);
        motor_R.backward();
        motor_L.backward();
        delay(40);
        motor_R.stop();
        motor_L.stop();
        delay(delaySpeed);
    break;
    case 2:// TURN LEFT
        Serial.println("State 2");
        motor_R.setSpeed(SPEED);
        motor_L.setSpeed(0);
        motor_R.backward();
        motor_L.backward();
        delay(40);
        motor_R.stop();
        motor_L.stop();
        delay(delaySpeed);
    break;
    case 3:// TURN RIGHT
        Serial.println("State 3");
        motor_R.setSpeed(0);
        motor_L.setSpeed(SPEED);
        motor_R.backward();
        motor_L.backward();
        delay(40);
        motor_R.stop();
        motor_L.stop();
        delay(delaySpeed);
    break;
    }
      
  }

}
