#include <Servo.h>

int WhiteLed = 13;
int GreenLed =  8;
int RedLed = 11;
int lightPen = A0;
int lightVal;
int servopin = 9;
int Relaypin = 7;
int SERVO_STARTPOS = 163;  
int SERVO_ENDPOS = 100;
bool on = true; //global variable 

// 163 STARTING POSTION OF SERVO MOTOR (this is for car 1 curious george)
// 100  CONFIRMED IS THE FINAL POSITION (CAR 1 curious george)

// 163 STARTING POSITION OF SERVO MOTOR (this is for car 2 scotty mcqueen)
// 100  CONFIRMED IS THE FINAL POSITION  (car 2 scotty mcqueen)

Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPen, INPUT);
  pinMode(WhiteLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(Relaypin, OUTPUT);
  myservo.write(SERVO_STARTPOS); 
  myservo.attach(servopin);

}

void loop() {
  // put your main code here, to run repeatedly:


//Always have the circuit do the following:
digitalWrite(WhiteLed, HIGH); // white LED ON


 
/* I added this due to the issue that we want the car to run automatcally however, I previosuly had the condition that if the photoresistor was under or below a value it would
either turn on or off the relay is proved to be a bad idea because in order for the car to run, it would have to depend and wait on the photoresistor to show a value.
Instead, the boolean statements allow the car to run independently as long as its conditon remains true. It will only change if the photoresistor is less than 500 
(the reaction has occured) and as a reuslt the car will stop. 
*/
if(on){
digitalWrite(Relaypin, HIGH);
myservo.write(SERVO_ENDPOS);
}
  else{
  digitalWrite(Relaypin, LOW);
  myservo.write(SERVO_STARTPOS);
   }
  

  // have this delay so that the solutions have time to settle down before recording the light value from the photoresistor, this time is NOT confirmed yet
delay(3000); 

lightVal = analogRead(lightPen);
Serial.println(lightVal);

//myservo.write(SERVO_STARTPOS);   might or might not need this           
 
// Once the solutions are settled, have the photoresistor begin to record the lught passing through the beaker
// Once the reaction occurs do the following:
if(lightVal > 200){
digitalWrite(RedLed, HIGH);
digitalWrite(GreenLed, LOW);
myservo.write(100);          // turn servo arm to position 100 (push down)
}

  else { 
  digitalWrite(GreenLed, HIGH);
  digitalWrite(RedLed,LOW );
  on = false;
  
  }


  



}
