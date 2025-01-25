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

//Always have the white LED ON
digitalWrite(WhiteLed, HIGH); // white LED ON


 
/* I added this since I previously had the condition that if the photoresistor was over or below a value it would
either turn on or off the relay. Instead, I made the "on" bool so that once the reaction occured the car can turn off. 
*/
if(on){
digitalWrite(Relaypin, HIGH);
myservo.write(SERVO_ENDPOS);
}
  else{
  digitalWrite(Relaypin, LOW);  // stops the car
  myservo.write(SERVO_STARTPOS); // servo goes to its original position 
   }
  

/*  delay is so that the solutions have time to settle down before recording the light value from the photoresistor, 
  otherwise this would go below the lightval threshold of 150
*/
delay(3000); 

lightVal = analogRead(lightPen); // records photoresistor 
Serial.println(lightVal); 

//myservo.write(SERVO_STARTPOS);  used testing/debugging purposes        
 
// Once the solutions are settled (after 3 secs), have the photoresistor begin to record the light passing through the beaker
if(lightVal > 150){
digitalWrite(RedLed, HIGH);
digitalWrite(GreenLed, LOW);
myservo.write(100);          // turn servo arm to position 100 (push down)
}
  // Once the reaction occurs do the following:
  else { 
  digitalWrite(GreenLed, HIGH);
  digitalWrite(RedLed,LOW );
  on = false;
  
  }


  



}
