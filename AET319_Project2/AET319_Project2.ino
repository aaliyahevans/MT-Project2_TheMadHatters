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
const int drinkSWITCH_1 = 3;
const int cookieSWITCH = 4;
const int drinkSWITCH_2 = 5;
const int aliceSWITCH = 6;


const int doorPin = 12;
const int alicePin = 11;


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
  Serial.begin(9600);
  pinMode(drinkSWITCH_1, INPUT);
  pinMode(drinkSWITCH_2, INPUT);
  pinMode(cookieSWITCH, INPUT);
  pinMode(aliceSWITCH, INPUT);


  
  
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
  
  if (drinkValue_1 == HIGH && cookieValue != HIGH) {

   /*
   
    COOKIE SWITCH
    - after the drink switch is used once, the LED for the cookie is lit up to signify that it's time to use it
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 60 degrees to get to 120
    - after setting down the cookie, the drink LED lights up again
   
   */
   
    // servo turns 60 degrees
    aliceServo.write(90);
    Serial.println("The drink has been placed down.");

  }

/*
    2ND DRINK SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - the cookie has been set down, so the servo is at 135 degrees
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/
   
    // checking to see if the 1st drink AND cookie have been used
    if ((drinkValue_1 == HIGH && cookieValue  == HIGH && drinkValue_2 != HIGH)) {
    // servo turns to 120 degrees
    aliceServo.write(0);
    Serial.println("Both the drink and cookie have been used.");

    
/*
    ALICE SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/
    }

 // checking to see if every switch has been completed before the Alice servo turns for the last time
    if (drinkValue_1 == HIGH && cookieValue == HIGH && drinkValue_2 == HIGH) {
    // servo turns to 180 degrees
    aliceServo.write(18);
      if (aliceValue == HIGH) {
          doorServo.write(90);
        }
    } 
  

    else {
      aliceServo.write(0);
      doorServo.write(0); 
    }

}
