/*
  06 - Knight Rider (Back and Forth)
  The light sweeps across the LEDs and then comes back,
  like the scanner on a certain talking car.

  Wiring (each LED has its own 220 ohm resistor):
    Pins 8, 9, 10, 11 -> resistor -> LED (+), LED (-) -> GND
*/

const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};
const int SPEED = 120;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Forward: first LED to last LED
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(SPEED);
    digitalWrite(ledPins[i], LOW);
  }

  // Backward: second-to-last LED back to the second LED
  // (skipping the ends so they don't flash twice in a row)
  for (int i = NUM_LEDS - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(SPEED);
    digitalWrite(ledPins[i], LOW);
  }
}
