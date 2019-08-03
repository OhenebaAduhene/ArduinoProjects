//variables for L298N pins connections on the arduino 
const int  in1 =  4;
const int in2 = 5;
const int in3 = 6;
const int in4 = 7;
const int enA = 9;
const int enB = 10;


//variables for speed of the dc motor
const int motorSpeedA = 100;
const int motorSpeedB = 100;

void setup() {
  // put your setup code here, to run once:
   //variables for the dc motors using L298N that moves the car
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void forward(){
   //Move Arduino Robot Car Foward
   // Set Motor A forward
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   // Set Motor B forward
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
    
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
  }

  void stopMoving(){
   //Stop the Arduino Robot Car
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
  }

  void left(){
  //Arduino Robot Car turns left direction
  //Turn off Motor A 
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   //Turn on Motor B forward
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
    
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}

void right(){
  //Arduino Robot Car turns left direction
  //Turn on Motor A 
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   //Turn off Motor B forward
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
    
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}

void back(){
  //Move Arduino Robot Car Foward
   // Set Motor A Backward
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   // Set Motor B forward
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
    
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}


void loop() {
  // put your main code here, to run repeatedly:
   back();
   delay(5000);
   stopMoving();
   delay(1000);
   left();
   delay(1000);
   stopMoving();
   delay(1000);
}
