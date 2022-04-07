/*

Alice in Wonderland Enclosure
Team Name: The Mad Hatters
Team Members: Aaliyah and Krista
Description: Button and servo program
*/

// adding servo code library
#include<Servo.h>;

// VARIABLES
Servo myServo;
const int buttonPin = 7;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
