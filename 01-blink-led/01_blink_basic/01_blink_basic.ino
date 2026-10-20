/*
  01 - Blink (Basic)
  Turns one LED on for one second, then off for one second, forever.

  Wiring:
    Pin 13 -> 220 ohm resistor -> LED long leg (+)
    LED short leg (-) -> GND
*/

void setup() {
  // Runs once when the board starts.
  pinMode(13, OUTPUT);   // Tell the Arduino pin 13 will send power OUT
}

void loop() {
  // Runs over and over, forever.
  digitalWrite(13, HIGH);  // Turn the LED ON (5 volts)
  delay(1000);             // Wait 1000 milliseconds (1 second)
  digitalWrite(13, LOW);   // Turn the LED OFF (0 volts)
  delay(1000);             // Wait 1 second
}
