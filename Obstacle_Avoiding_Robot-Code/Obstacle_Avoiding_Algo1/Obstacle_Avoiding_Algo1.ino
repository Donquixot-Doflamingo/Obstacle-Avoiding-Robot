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

long distance = 0, duration = 0, rDistance = 0, lDistance = 0;

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
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
    delay(350);
    
  // resetting it to 90 for further process
//  myservo.write(90);
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
    motor2.run(BACKWARD);
    motor4.run(FORWARD);
  
    delay(350);
  
  // resetting it to 90 for further process
//  myservo.write(90);
}

int distanceCalculator(){
   digitalWrite(trigpin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin , LOW);

  duration = pulseIn(echopin , HIGH);
  int dis = (duration / 2) / 28.5 ;
  Serial.println("Distance : ");
  Serial.println(dis);
  return dis;
}


// making the ultrasound sensor look right side
int rightSide(){
     myservo.write(0);
    delay(150);
    int distance_R = distanceCalculator();
    return distance_R;
}

// making the ultrasound sensor look left side
int leftSide(){
     myservo.write(170);
    delay(150);
    int distance_L = distanceCalculator();
    return distance_L;
}


void loop()
{
  myservo.write(90);
  distance = distanceCalculator();
  Serial.println("Distance from forward: ");
  Serial.println(distance);
  if (distance < set)
  {
    rDistance = rightSide();
    Serial.println("Distance from right: ");
    Serial.println(rDistance);
    if(rDistance < set){
      lDistance = leftSide();
      Serial.println("Distance from left: ");
      Serial.println(lDistance);
      if(lDistance < set){
        Serial.println("No way out area blocked");
      }
      else{
        delay(10);
      }
    }
    else{
      delay(10);
      Right();
    }
  }
  else
  {
    Forward();
  }
 
}
