/*
  06 - Light Meter (LED bar graph)
  Four LEDs show how bright the room is: more light = more LEDs on.
  Combines the photoresistor with the multi-LED wiring from Project 01.

  Wiring (see schematic_4_light_meter.png in this folder):
    5V -> photoresistor -> pin A0
    Pin A0 -> 10k ohm resistor -> GND
    Pins 8, 9, 10, 11 -> 220 ohm resistor -> LED (+), LED (-) -> GND

  Adjust LIGHT_MIN and LIGHT_MAX to match the readings from sketch 01.
*/

const int LDR_PIN = A0;
const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};

const int LIGHT_MIN = 100;   // reading in a dark room -> 0 LEDs on
const int LIGHT_MAX = 900;   // reading in a bright room -> all 4 LEDs on

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int light = analogRead(LDR_PIN);

  // Convert the reading to a level from 0 to 4
  int level = map(light, LIGHT_MIN, LIGHT_MAX, 0, NUM_LEDS);
  level = constrain(level, 0, NUM_LEDS);

  // Turn on the first "level" LEDs, turn off the rest
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], i < level ? HIGH : LOW);
  }

  delay(50);
}
