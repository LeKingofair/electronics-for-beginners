/*
  02 - Button with INPUT_PULLUP
  Same result as sketch 01, but with one less part: the Arduino has a
  built-in pull-up resistor you can turn on in code.

  Wiring (see images/schematic_2_button_pullup.svg):
    Pin 2 -> button -> GND
    Pin 13 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND

  The catch: the logic is INVERTED.
    Button released -> pin 2 reads HIGH
    Button pressed  -> pin 2 reads LOW  (it is connected to GND)
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 13;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // turn on the internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {   // LOW means pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
