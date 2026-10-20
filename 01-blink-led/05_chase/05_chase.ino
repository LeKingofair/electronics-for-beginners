/*
  05 - LED Chase
  A single light "runs" across four LEDs, then starts over.
  Uses an ARRAY and a FOR LOOP so the code stays short.

  Wiring (each LED has its own 220 ohm resistor):
    Pins 8, 9, 10, 11 -> resistor -> LED (+), LED (-) -> GND
*/

const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};  // List of LED pins
const int SPEED = 150;                          // Lower = faster

void setup() {
  // Set every pin in the list as an output
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Go through each LED one at a time
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);  // turn this one on
    delay(SPEED);
    digitalWrite(ledPins[i], LOW);   // turn it off before moving on
  }
}
