/*
  01 - Button Hold (external pull-down resistor)
  The LED is ON while you hold the button and OFF when you let go.

  Wiring (see schematic_1_button_pulldown.png in this folder):
    5V -> button -> pin 2
    Pin 2 -> 10k ohm resistor -> GND      (the "pull-down" resistor)
    Pin 13 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND

  Why the pull-down resistor?
    Without it, pin 2 would "float" when the button is not pressed and
    could randomly read HIGH or LOW. The resistor gently pulls it to GND (LOW).
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 13;

void setup() {
  pinMode(BUTTON_PIN, INPUT);   // Pin 2 will READ a voltage
  pinMode(LED_PIN, OUTPUT);     // Pin 13 will SEND a voltage
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // HIGH (5V) or LOW (0V)

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);   // pressed -> LED on
  } else {
    digitalWrite(LED_PIN, LOW);    // released -> LED off
  }
}
