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
const int drinkSWITCH_1 = 6;
const int cookieSWITCH = 5;
const int drinkSWITCH_2 = 4;
const int aliceSWITCH = 3;

bool drinkUsed = false;
bool cookieUsed = false;
bool drinkUsed_2 = false;
bool aliceUsed = false;

const int doorPin = 12;
const int alicePin = 11;

int currentPosition = 0;
int currentPosition_door = 90;
int itemCounter = 0;



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
  */
  
  if (drinkValue_1 == HIGH) {
    drinkUsed = true; 
    currentPosition = 180;
    itemCounter++;
  }
    if (drinkUsed == true && cookieUsed == false) {
    // servo turns 60 degrees
    aliceServo.write(90);
    Serial.println("The drink has been placed down.");

}
  

   /*
   
    COOKIE SWITCH
    - because the drink switch was already used, the servo is at 90 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo back to 0 degrees to show that Alice is too big to get through the door again
 
   
   */
   
    // checking to see if the 1st drink AND cookie have been used
    if (cookieValue == HIGH) {
    cookieUsed = true;
    currentPosition = 90;
    itemCounter++;
    }
    
    if (cookieUsed == true && drinkUsed_2 == false) {   
  
    // servo turns to 120 degrees
    aliceServo.write(0);
    Serial.println("Both the drink and cookie have been used, but Alice still doesn't have the key.");

}
    
/*
    2ND DRINK SWITCH
    - the cookie has been set down, so the servo is at 0 degrees
    - when the cookie is placed down, the switch turns the servo 180 degrees to get to the final, small sized Alice and the key
   
*/
    

    

 // checking to see if every switch has been completed before the Alice servo turns for the last time
    if (drinkValue_2 == HIGH) {
    drinkUsed_2 = true;
    currentPosition = 0 ;
    itemCounter++;
    }
    if (drinkUsed_2 == true && cookieUsed == true && drinkUsed == true) {
    // servo turns to 180 degrees
    aliceServo.write(180);
    Serial.println("Alice has the key and is finally small enough to get through the door!");
    }

/*
    ALICE SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/ 


if (aliceValue == HIGH)
{aliceUsed = true;
currentPosition_door = 90;
}
if (aliceUsed == true && drinkUsed_2 == true) {
  doorServo.write(currentPosition_door);
 Serial.println("Alice made it out of the room! Hooray!");
  }
    

    
}
