/*
  02 - Night Light (Basic)
  The LED turns ON when it gets dark and OFF when it is bright.

  Wiring (see schematic_2_night_light.png in this folder):
    5V -> photoresistor -> pin A0
    Pin A0 -> 10k ohm resistor -> GND
    Pin 13 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND

  Setting the threshold:
    Run sketch 01 first. Note the number in bright light and the number
    when you cover the sensor, then pick a THRESHOLD between the two.
*/

const int LDR_PIN = A0;
const int LED_PIN = 13;
const int THRESHOLD = 400;   // change this to suit your room

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int light = analogRead(LDR_PIN);

  if (light < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);   // dark -> light on
  } else {
    digitalWrite(LED_PIN, LOW);    // bright -> light off
  }
}
