//Include the motor driver library

//speaker
#define NOTE_B5 988
#define NOTE_F5 698

//Motor A input pins(IN1, IN2). Used to control the spinning direction of Motor A
#define IN1 8 // connect IN1 on the H-Bridge to Arduino pin 8
#define IN2 9 // connect IN2 on the H-Bridge to Arduino pin 9

//Motor B input pins(IN3, IN4). Used to control the spinning direction of Motor B
#define IN3 12 // connect IN3 on the H-Bridge to Arduino pin 12
#define IN4 13 // connect IN4 on the H-Bridge to Arduino pin 13
//Define the sensor pins
#define trigPin1 7
#define trigPin2 4
#define trigPin3 2
#define echoPin1 6
#define echoPin2 5
#define echoPin3 3

#define ENA 10 //Enables PWM signal for Motor A


//Set the speed of the motors
#define MotorSpeed 70

//Create objects for the motors
//AF_DCMotor motor1(1);
//AF_DCMotor motor2(2);

//Keep the loop running when I want to
int i=0;
// connect black wire(-) to GND and red wire(+) to pin 9
void Stop();
int sensorOne();
float sensorTwo();
int sensorThree();
void forward();
void backward();
void right();
void left();

void setup() {
  Serial.begin(38400);
  //Set Trigpins as output pins
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  //Set Echopins as input pins
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);  
  //Set PWM pins as OUTPUT pins
 // pinMode(ENA, OUTPUT);
 // pinMode(ENB, OUTPUT);
  //analogWrite(ENA, MotorSpeed);
  //analogWrite(ENB, MotorSpeed);
  //Include the motor speeds
//  motor1.setSpeed(Speed);
//  motor2.setSpeed(Speed);
  //Set up speaker pin
  pinMode(9, OUTPUT);
}


void loop() {
  float centerSensor = sensorTwo();
  float leftSensor = sensorOne();
  float rightSensor = sensorThree();

  if (centerSensor <= 20) {
    backward();
    tone(11,NOTE_F5,75);
    Serial.println("Backing up!");
    delay(25);
    Stop();
    delay(50);
    noTone(11);
  }
  else if (centerSensor <= 25) {
    Stop();
    Serial.println("Stop");
    delay(75);
  } else if (centerSensor <= 100) {
    forward();
    delay(50);
    Stop();
    delay(25);
  } else {
      if (leftSensor - rightSensor > 3 ) {
        right();
        Serial.println("Right");
        delay(50);
      } else if (rightSensor - leftSensor > 3) {
        left();
        Serial.println("Left");
        delay(50);  
      }
      Serial.println("Stop");
      Stop();
      delay(25);
}


}
//for the speaker
//  for(i=700;i<800;i++){
//  tone(10,i);
//  delay(3);
//  }
//  for(i=800;i>700;i--){
//  tone(8,i);
//  delay(3);
//  }
  //delay(500);


//Get sensor values
int sensorOne() {
  //pulse output
  //digitalWrite(trigPin1, LOW);
  //delayMicroseconds(4);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  float t = pulseIn(echoPin1, HIGH); //input pulse and save it variable
  float cm = t / 29 / 2; //time convert distance
  Serial.print("Sensor one: ");
  Serial.println(cm);
  return cm;
}

//Get sensor values
float duration_us2;
float cm2;
float sensorTwo() {
  //pulse output
  //digitalWrite(trigPin2, LOW);
  //delayMicroseconds(4);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration_us2 = pulseIn(echoPin2, HIGH);//input pulse and save it veriable
  cm2 = duration_us2 / 29 / 2; //time convert distance
  Serial.print("Sensor two: ");
  Serial.println(cm2);
  return cm2;
}

//Get sensor values
int sensorThree() {
  //pulse output
  //digitalWrite(trigPin3, LOW);
  //delayMicroseconds(4);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  float t = pulseIn(echoPin3, HIGH);//input pulse and save it veriable
  float cm = t / 29 / 2; //time convert distance

  Serial.print("Sensor three: ");
  Serial.println(cm);
  return cm;
}

//Motor functions:

void forward() {
    //Motor A running forward
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
    //Motor B running forward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void backward() {
    //Motor A running forward
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    //Motor B running forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void left() {
    //Motor A stopping
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
    //Motor B running forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void right() {
    //Motor A running forward, Motor B running backward
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    //Motor B stopping
    //digitalWrite(IN3, LOW);
    //digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void Stop() {
    //Motor A stopping
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    //Motor B stopping
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
