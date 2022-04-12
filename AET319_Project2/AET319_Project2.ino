/*

Alice in Wonderland Enclosure
Team Name: The Mad Hatters
Team Members: Aaliyah and Krista
Description: Button and servo program
*/

// adding servo code library
#include<Servo.h>;

// VARIABLES
Servo aliceServo;
Servo doorServo;

const int cookiePin = 4;
const int drinkPin1 = 5;
const int drinkPin2 = 6;
const int alicePin = 7;

const int cookieLED = 8; 
const int drink1LED = 9;
const int aliceLED = 10;





void setup() {
  // put your setup code here, to run once:

   /*
    START!
    - setting up pins, LEDs, and making sure they're noted as being either inputs or outputs
    - the servo must rotate to 0 degrees if it isn't already as its default angle is 90

  */
  
  aliceServo.attach(9);
  pinMode(drinkPin1, INPUT);
  pinMode(cookiePin, INPUT);
  pinMode(drinkPin2, INPUT);
  pinMode(alicePin, INPUT);

  pinMode(cookieLED, OUTPUT);
  pinMode(drink1LED, OUTPUT);
  pinMode(aliceLED, OUTPUT);
  
  aliceServo.write(0);
  digitalWrite(drink1LED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * 
    1ST DRINK SWITCH
    - the servo is at 0 degrees because nothing has been used yet
    - once the drink is set down, the cookie LED lights up to signify that's the next step
    *
    */
  
  if(digitalRead(drinkPin1) == HIGH) {

    // servo turns 45 degrees
    aliceServo.write(45);
    // cookie LED lights up to signify next step
    digitalWrite(drink1LED, LOW);
    digitalWrite(cookieLED, HIGH);
    
    
    } 
    
    else {
      
      aliceServo.write(0);
    
    }
  

  
  /*
    
    COOKIE SWITCH
    - after the drink switch is used once, the LED for the cookie is lit up to signify that it's time to use it
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
    - after setting down the cookie, the drink LED lights up again
  
  */

 if(digitalRead(cookiePin) == HIGH) {
    
    // alice turns to the 90 degree angle
    aliceServo.write(90);
    //
    digitalWrite(drinkLED, HIGH);
    
    // other LEDs turn off to signify that it's not time to use them
    digitalWrite(cookieLED, LOW);
    digitalWrite(aliceLED, LOW);

    } 
    
    else {
    
      aliceServo.write(45);
    
    }


/*
    
    2ND DRINK SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - the cookie has been set down, so the servo is at 135 degrees
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90
   
*/

  if(digitalRead(drinkPin2) == HIGH) {
    
    aliceServo.write(180);
     digitalWrite(aliceLED, HIGH);

    // other LEDs turn off to signify that it's not time to use them
    digitalWrite(drinkLED, LOW);
    digitalWrite(cookieLED, LOW);
   
    
    } 
    
    else {
      
      aliceServo.write(135);
    
    }
  
/*
    ALICE SWITCH
    - after the cookie switch is used, the LED for the drink is lit up again to signify that it's time to use it a second time
    - because the drink switch was already used, the servo is at 45 degrees since it's already turned once
    - when the cookie is placed down, the switch turns the servo another 45 degrees to get to 90

       
*/
    

  if(digitalRead(alicePin) == HIGH) {
    
    doorServo.write(180);

    
    // other LEDs turn off to signify they don't need to be used anymore
    digitalWrite(drinkLED, LOW);
    digitalWrite(cookieLED, LOW);
    digitalWrite(aliceLED, LOW);

    } 
    
    else {

  
      
    }
