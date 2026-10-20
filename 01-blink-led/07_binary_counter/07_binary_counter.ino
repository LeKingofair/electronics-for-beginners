/*
  07 - Binary Counter
  Four LEDs count from 0 to 15 in binary. An LED that is ON is a 1,
  an LED that is OFF is a 0.

  Wiring (each LED has its own 220 ohm resistor):
    Pin 8  -> LED 1  (the "1s" place, rightmost bit)
    Pin 9  -> LED 2  (the "2s" place)
    Pin 10 -> LED 3  (the "4s" place)
    Pin 11 -> LED 4  (the "8s" place, leftmost bit)

  Example: 5 = 0101 -> LEDs on pins 10 and 8 are ON.
*/

const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Count from 0 to 15 (4 bits)
  for (int number = 0; number < 16; number++) {
    // Check each bit of the number and set the matching LED
    for (int bit = 0; bit < NUM_LEDS; bit++) {
      digitalWrite(ledPins[bit], bitRead(number, bit));
    }
    delay(700);
  }
}
