/*
  05 - Two Buttons: ON and OFF
  One button turns the LED on, a second button turns it off.

  Wiring (see images/schematic_3_two_buttons.svg):
    Pin 2 -> ON button  -> GND
    Pin 3 -> OFF button -> GND
    Pin 13 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND
*/

const int ON_BUTTON = 2;
const int OFF_BUTTON = 3;
const int LED_PIN = 13;

void setup() {
  pinMode(ON_BUTTON, INPUT_PULLUP);
  pinMode(OFF_BUTTON, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(ON_BUTTON) == LOW) {    // ON button pressed
    digitalWrite(LED_PIN, HIGH);
  }

  if (digitalRead(OFF_BUTTON) == LOW) {   // OFF button pressed
    digitalWrite(LED_PIN, LOW);
  }
  // If neither is pressed, the LED simply stays however it was.
}
