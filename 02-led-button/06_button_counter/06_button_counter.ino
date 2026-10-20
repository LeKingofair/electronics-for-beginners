/*
  06 - Button Counter (binary)
  Each button press adds 1 to a counter. Four LEDs show the count in
  binary, from 0 to 15, then it wraps back to 0.
  Combines Project 01 (binary LEDs) with a button.

  Wiring (see images/schematic_4_button_four_leds.svg):
    Pin 2 -> button -> GND
    Pins 8, 9, 10, 11 -> 220 ohm resistor -> LED (+), LED (-) -> GND
      Pin 8  = the "1s" place (rightmost bit)
      Pin 9  = the "2s" place
      Pin 10 = the "4s" place
      Pin 11 = the "8s" place (leftmost bit)
*/

const int BUTTON_PIN = 2;
const int NUM_LEDS = 4;
const int ledPins[NUM_LEDS] = {8, 9, 10, 11};

int count = 0;             // the number being displayed
bool wasPressed = false;   // was the button pressed last time through loop()?

void showNumber(int number) {
  for (int bit = 0; bit < NUM_LEDS; bit++) {
    digitalWrite(ledPins[bit], bitRead(number, bit));
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  showNumber(count);
}

void loop() {
  bool pressed = (digitalRead(BUTTON_PIN) == LOW);

  // Count only at the moment the button goes from "not pressed" to "pressed"
  if (pressed && !wasPressed) {
    count = (count + 1) % 16;   // 15 + 1 wraps back to 0
    showNumber(count);
  }

  // Short pause after any change to ignore contact bounce
  if (pressed != wasPressed) {
    delay(20);
  }

  wasPressed = pressed;
}
