/*
  08 - Random Twinkle
  Picks a random LED, flashes it for a random amount of time.
  Looks like twinkling lights.

  Wiring (each LED has its own 220 ohm resistor):
    Pins 8, 9, 10, 11 -> resistor -> LED (+), LED (-) -> GND
*/

const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Read an unconnected analog pin to get a different random
  // sequence each time the board starts.
  randomSeed(analogRead(A0));
}

void loop() {
  int led = random(0, NUM_LEDS);        // random number from 0 to 3
  int onTime = random(50, 400);         // flash for 50-399 ms
  int offTime = random(50, 300);        // pause for 50-299 ms

  digitalWrite(ledPins[led], HIGH);
  delay(onTime);
  digitalWrite(ledPins[led], LOW);
  delay(offTime);
}
