/*
  03 - Two LEDs Alternating
  Two LEDs take turns: one on while the other is off.

  Wiring (each LED has its own 220 ohm resistor):
    Pin 8 -> resistor -> LED 1 (+), LED 1 (-) -> GND
    Pin 9 -> resistor -> LED 2 (+), LED 2 (-) -> GND
*/

const int LED_1 = 8;
const int LED_2 = 9;
const int WAIT = 500;  // milliseconds

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() {
  digitalWrite(LED_1, HIGH);  // LED 1 on
  digitalWrite(LED_2, LOW);   // LED 2 off
  delay(WAIT);

  digitalWrite(LED_1, LOW);   // LED 1 off
  digitalWrite(LED_2, HIGH);  // LED 2 on
  delay(WAIT);
}
