#include <Servo.h>



int WhiteLed = 13;
int GreenLed =  10;
int RedLed = 11;
int lightPen = A0;
int lightVal;
int dv = 250; //250 miliseconds
int servopin = 9;
int switchpin = 8;
int switchValue;
int Relaypin = 7;
int servopos = 60;
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPen, INPUT);
  pinMode(switchpin, INPUT);
  digitalWrite(switchpin, HIGH);
  pinMode(WhiteLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(Relaypin, OUTPUT);

  myservo.attach(servopin);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchValue = digitalRead(switchpin);
  Serial.println(switchValue);

  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv);

  //Always have the white LED on 
  digitalWrite(WhiteLed, HIGH);
  //digitalWrite(Relaypin, LOW);

 
if(switchValue == 1){
myservo.write(60); // STARTING POSTION OF SERVO MOTOR
digitalWrite(Relaypin, LOW);
}

  else{
  digitalWrite(Relaypin, HIGH);
  myservo.write(155); //If button is pressed I.E circuit connects, then turn the servo motor and NOTE: also filp the relay on too
  }


  //if light val is over some value, then change the position of the motor
if(lightVal > 500){
digitalWrite(RedLed, HIGH);
digitalWrite(GreenLed, LOW);
//digitalWrite(Relaypin, HIGH);
}
  else { 
  digitalWrite(GreenLed, HIGH);
  digitalWrite(RedLed,LOW );
  digitalWrite(Relaypin, LOW);
  }



}
