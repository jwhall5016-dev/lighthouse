#include <Servo.h>

// Servo object
Servo servo;  

// Constants
const int servoPin = 3;       // Pin number for lamp rotation servo
const int ledLampPin = 5;     // Pin number for LED in the rotating lamp 
const int ledBodyPin = 7;     // Pin number for LED in the body of the lighthouse
const int switchPin = 9;      // Pin number for the On/Off switch

//Global Variables
int pos = 0;                  // Current position of the lamp servo       

// Initialise the servo, and set the pin modes for the LEDs and switch
void setup() {
  servo.attach(servoPin);
  pinMode(ledLampPin, OUTPUT);
  pinMode(ledBodyPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  servo.write(0);
}

// The main loop of the program
// Check switch is on and start/shutdown the lighthouse
void loop() {  
  // Check if the switch is on
  int switchState = digitalRead(switchPin);

  // If the switch is on (pulled LOW), then activate the lighthouse
  if (switchState == LOW) {
    
    // Turn on both the LEDs
    digitalWrite(ledLampPin, HIGH);
    digitalWrite(ledBodyPin, HIGH);

    // Turn the servo to full extent slowly, then return at a constant speed
    for (pos = 0; pos < 180; pos++){
      servo.write(pos);
      delay(20);
    }
     for (pos = 180; pos > 0; pos--){
      servo.write(pos);
      delay(20);
    }
  }
  // If the switch is off (pulled HIGH), shut down the lighthouse
  else {
   
    // Return the lighthouse to it's 0 position
    for (pos = pos; pos > 0; pos--){
      servo.write(pos);
      delay(20);
    }

    // Turn off the LEDS
    digitalWrite(ledLampPin, LOW);
    digitalWrite(ledBodyPin, LOW);
  }
}