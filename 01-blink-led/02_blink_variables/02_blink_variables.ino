/*
  02 - Blink with Variables
  Same circuit as sketch 01, but the settings live at the top
  so they are easy to change. Try different values!

  Wiring:
    Pin 13 -> 220 ohm resistor -> LED long leg (+)
    LED short leg (-) -> GND
*/

const int LED_PIN = 13;   // Which pin the LED is on
const int ON_TIME = 200;  // How long the LED stays on (milliseconds)
const int OFF_TIME = 800; // How long the LED stays off (milliseconds)

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(ON_TIME);
  digitalWrite(LED_PIN, LOW);
  delay(OFF_TIME);
}

/*
  Try this:
    - ON_TIME = 50, OFF_TIME = 50   -> fast flicker
    - ON_TIME = 1000, OFF_TIME = 100 -> mostly on
    - Moving the LED to another pin? Only change LED_PIN.
*/
