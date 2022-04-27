#include <AFMotor.h>
#include <Servo.h>

// Motor port number
const int MOTOR_2 = 2; 
const int MOTOR_4 = 4; 

// creating motor object of 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); 
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); 

// defining servo
Servo myservo;

// ultrasound sensor
#define echopin A4 // echo pin
#define trigpin A5// Trigger pin

//========================================================
//  Initialization
//========================================================

// defing the range of detection for ultrasound sensor
int set = 20;

long distance = 0, duration = 0;

void setup() {
  
  // setting up servo at pin and making it facing forward
  myservo.attach(10);
  myservo.write(90);

  // SETTING THE PIN MODE OF ULTRASOUND SENSOR
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );

  // set the motor speed to 0-255
  motor2.setSpeed(200);
  motor4.setSpeed(255);

  // initialing the board
  Serial.begin(9600);
  Serial.println("Start");
}

//========================================================
//  Main
//========================================================

// if the car is commanded to move right
void Right(){
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
    delay(500);
    
  // resetting it to 90 for further process
  myservo.write(90);
}

void Forward(){
    motor2.run(FORWARD);
    motor4.run(FORWARD);
}

void Backward(){
    motor2.run(BACKWARD);
    motor4.run(BACKWARD);
}


// if the car is commanded to move left
void Left(){
    motor2.run(BACKWARD);
    motor4.run(FORWARD);
    motor2.run(BACKWARD);
    motor4.run(FORWARD);
    motor2.run(BACKWARD);
    motor4.run(FORWARD);
    motor2.run(BACKWARD);
    motor4.run(FORWARD);
  
    delay(500);
  
  // resetting it to 90 for further process
  myservo.write(90);
}

bool distanceCalculator(){
   digitalWrite(trigpin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin , LOW);

  duration = pulseIn(echopin , HIGH);
  int dis = (duration / 2) / 28.5 ;
  Serial.println("Distance : ");
  Serial.println(dis);
  if(dis > set){
    return true;
  }
  return false;
}


// making the ultrasound sensor look right side
int rightSide(){
     myservo.write(0);
    delay(250);
}

// making the ultrasound sensor look left side
int leftSide(){
     myservo.write(170);
    delay(250);
}


void loop()
{
  myservo.write(90);
  if (!distanceCalculator())
  {
    rightSide();
    
    if(!distanceCalculator()){
      leftSide();
 
      if(!distanceCalculator()){
        Serial.println("No way out area blocked");
      }
      else{
        Left();
      }
    }
    else{
      Right();
    }
  }
  else
  {
    Forward();
  }
 
}
