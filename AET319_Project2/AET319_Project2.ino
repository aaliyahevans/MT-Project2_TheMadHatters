/*

Alice in Wonderland Enclosure
Team Name: The Mad Hatters
Team Members: Aaliyah and Krista
Description: Button and servo program
*/

// adding servo code library
#include<Servo.h>

// VARIABLES
Servo doorServo;
Servo aliceServo;
int drinkValue_1;
int drinkValue_2;
int aliceValue;
int cookieValue;



// CONSTANTS
const int cookieSWITCH = 4;
const int drinkSWITCH_1 = 5;
const int drinkSWITCH_2 = 6;
const int aliceSWITCH = 7;
const int doorPin = 11;
const int alicePin = 12;


const int cookieLED = 8; 
const int drinkLED = 9;
const int aliceLED = 10;


void setup() {
  // put your setup code here, to run once:

   /*
    START
    - the servo must rotate to 0 degrees if it isn't already as its default angle is 90
    - once the drink is set down, the cookie LED lights up to signify that's the next step
  */
  
  aliceServo.attach(alicePin);
  aliceServo.write(0);
  doorServo.attach(doorPin);
  doorServo.write(0);
  
  pinMode(drinkSWITCH_1, INPUT);
  pinMode(drinkSWITCH_2, INPUT);
  pinMode(cookieSWITCH, INPUT);
  pinMode(aliceSWITCH, INPUT);

  pinMode(drinkLED, OUTPUT);
  pinMode(cookieLED, OUTPUT);
  pinMode(aliceLED, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:


  drinkValue_1 = digitalRead(drinkSWITCH_1);
  drinkValue_2 = digitalRead(drinkSWITCH_2);
  aliceValue = digitalRead(aliceSWITCH);
  cookieValue = digitalRead(cookieSWITCH);

 
 
  /*
    1ST DRINK SWITCH
    - the servo is at 0 degrees because nothing has been used yet
    - once the drink is set down, the cookie LED lights up to signify that's the next step
  */
  
  if (drinkValue_1 == HIGH) {

   /*
   
    COOKIE SWITCH
    - after the drink switch is used once, the LED for the cookie is lit up to signify that it's time to use it
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 60 degrees to get to 120
    - after setting down the cookie, the drink LED lights up again
   
   */
   
    // servo turns 60 degrees
    aliceServo.write(60);
    // cookie LED lights up to signify next step
    digitalWrite(cookieLED, HIGH);
    digitalWrite(drinkLED, LOW);
    digitalWrite(aliceLED, LOW);

/*
    2ND DRINK SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - the cookie has been set down, so the servo is at 135 degrees
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/
   
    // checking to see if the 1st drink AND cookie have been used
    if ((drinkValue_1 == HIGH && cookieValue  == HIGH)) {
    // servo turns to 120 degrees
    aliceServo.write(120);
    // drink LED lights up again to signify next step
    digitalWrite(cookieLED, LOW);
    digitalWrite(drinkLED, HIGH);
    digitalWrite(aliceLED, LOW);
    
/*
    ALICE SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/

 // checking to see if every switch has been completed before the Alice servo turns for the last time
    if (drinkValue_1 == HIGH && cookieValue == HIGH && drinkValue_2 == HIGH) {
    // servo turns to 180 degrees
    aliceServo.write(180);
    // Alice LED lights up again to signify next step needed to open the door
    digitalWrite(aliceLED, HIGH);
      if (aliceValue == HIGH) {
          doorServo.write(90);
    // all LEDs turn off
    digitalWrite(cookieLED, LOW);
    digitalWrite(drinkLED, LOW);
    digitalWrite(aliceLED, LOW);
        }
    } 
  }
}
    else {
      aliceServo.write(0);
      doorServo.write(0); 
    }
  
}
