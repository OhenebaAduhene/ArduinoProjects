//variables for L298N pins connections on the arduino 
#define in1  4
#define in2  5
#define in3  6
#define in4  7
#define enA  9
#define enB 10


//variables for speed of the dc motor
const int motorSpeedA = 255;
const int motorSpeedB = 255;

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

void foward(){
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
   foward();
  delay(5000);

}
