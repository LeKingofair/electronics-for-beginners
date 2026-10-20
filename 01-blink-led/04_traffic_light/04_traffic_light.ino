/*
  04 - Traffic Light
  Three LEDs cycle like a real traffic light, with a different
  amount of time for each color.

  Wiring (each LED has its own 220 ohm resistor):
    Pin 8  -> resistor -> GREEN LED  (+), (-) -> GND
    Pin 9  -> resistor -> YELLOW LED (+), (-) -> GND
    Pin 10 -> resistor -> RED LED    (+), (-) -> GND
*/

const int GREEN = 8;
const int YELLOW = 9;
const int RED = 10;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // Green: go
  digitalWrite(GREEN, HIGH);
  delay(4000);
  digitalWrite(GREEN, LOW);

  // Yellow: slow down
  digitalWrite(YELLOW, HIGH);
  delay(1500);
  digitalWrite(YELLOW, LOW);

  // Red: stop
  digitalWrite(RED, HIGH);
  delay(4000);
  digitalWrite(RED, LOW);
}
