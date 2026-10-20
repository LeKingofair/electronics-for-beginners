/*
  04 - Dimmable Night Light
  Instead of just on/off, the LED gets brighter the darker the room is.

  Wiring (see schematic_3_dimmable_night_light.png in this folder):
    5V -> photoresistor -> pin A0
    Pin A0 -> 10k ohm resistor -> GND
    Pin 9 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND

  New ideas:
    - PWM: analogWrite(pin, 0-255) rapidly switches a pin on and off to
      fake an in-between voltage. Only pins marked with ~ can do this
      (3, 5, 6, 9, 10, 11 on an Uno). Pin 13 can NOT, which is why we
      moved the LED to pin 9.
    - map() converts a number from one range to another.
    - constrain() keeps a number inside a range.
*/

const int LDR_PIN = A0;
const int LED_PIN = 9;

const int DARK_VALUE = 200;     // reading in a dark room (use sketch 01 to find yours)
const int BRIGHT_VALUE = 800;   // reading in a bright room

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int light = analogRead(LDR_PIN);

  // Dark reading -> 255 (full brightness), bright reading -> 0 (off)
  int brightness = map(light, DARK_VALUE, BRIGHT_VALUE, 255, 0);
  brightness = constrain(brightness, 0, 255);

  analogWrite(LED_PIN, brightness);
  delay(10);
}
