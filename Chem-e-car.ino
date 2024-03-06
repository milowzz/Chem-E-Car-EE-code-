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
  pinMode(WhiteLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(Relaypin, OUTPUT);
  
  digitalWrite(switchpin, HIGH);

  myservo.attach(servopin);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchValue = digitalRead(switchpin); //read in the voltage value from the switch
  Serial.println(switchValue); // this is unessarcy, but good practice to check if the adruino is keeping up the signal

  lightVal = analogRead(lightPen); // read in the voltage of the photoresistor 
  Serial.println(lightVal);       // print the value to the serial monitor 
  delay(dv);                      // 250milisec 

  //Always have the white LED on 
  digitalWrite(WhiteLed, HIGH);
  

// if the switch is off, have the servo stay in starting position and have the relay off
if(switchValue == 1){      
myservo.write(60); // STARTING POSTION OF SERVO MOTOR
digitalWrite(Relaypin, LOW);
}
  //when the switch is flipped turn on the relay, which will connect the battery and motor, also turns the servo so that it pushes on the syringe to begin reaction
  else{ 
  digitalWrite(Relaypin, HIGH);
  myservo.write(155); //If button is pressed I.E circuit connects, then turn the servo motor and NOTE: also filp the relay on too
  }


// STARTING SEQUENCE, the light passing through the beaker via led will be recorded, At this time the RED led will be on
if(lightVal > 500){
digitalWrite(RedLed, HIGH);
digitalWrite(GreenLed, LOW);

}
  // once the reaction happens, lightval will decrease and then cut the relay from the battery and stop the car as a whole. 
  //The LED will turn green to confirm this occured 
  else { 
  digitalWrite(GreenLed, HIGH);
  digitalWrite(RedLed,LOW );
  digitalWrite(Relaypin, LOW);
  }



}
