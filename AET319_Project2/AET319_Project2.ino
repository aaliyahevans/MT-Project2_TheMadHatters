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
int itemCounter;
int itemValue;
int prevItemValue;
int aliceValue;


// CONSTANTS
const int itemSWITCH = 4;
const int aliceSWITCH = 7;
const int doorPin = 11;
const int alicePin = 12;



void setup() {
  // put your setup code here, to run once:

  
  aliceServo.attach(alicePin);
  aliceServo.write(0);
  doorServo.attach(doorPin);
  doorServo.write(0);
  Serial.begin(9600);
  pinMode(itemSWITCH, INPUT);
  pinMode(aliceSWITCH, INPUT);



  
  
}

void loop() {
  // put your main code here, to run repeatedly:

 
/* ALICE SERVO & SWITCHES
 * the code is set up so that ANY food item or drink item, regardless of label, turns the servo consisting of the different alice sizes
 * the order of operations recommended to tell the story (as alice first drinks the bottle that shrinks her, eats the cookie that makes her giant, and then drinks the bottle again in the story) will be told through external design cues and affordances
 * once the alice servo turns to 180 degrees, the user should be able to grab the detachable switch with the key to open the door to use for the door switch
*/
  itemValue = digitalRead(itemSWITCH);
  if(itemValue != prevItemValue) {
    if(itemValue == HIGH) {
    itemCounter++;
    aliceServo.write(60 * itemCounter);
    if (itemCounter > 3) {
      itemCounter = 0;
      aliceServo.write(0);
      }
    }
  prevItemValue = itemValue;
}


/* DOOR SERVO & SWITCH
 * set up to be more simple than the alice servo 
 * once the alice switch is completed
*/
aliceValue = digitalRead(aliceSWITCH);
if (aliceValue == HIGH) {
        doorServo.write(180);
        } 
        else {
          doorServo.write(0);
          }

}
  
/*
    ALICE SWITCH
    - user gets Alice switch from the wheel and uses it on the door switch
    - the door turns to let Alice out and goes back to normal position once the switch isn't on anymore

*/
    


    
      

 