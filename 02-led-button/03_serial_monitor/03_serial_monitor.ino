/*
  03 - Serial Monitor
  Prints a message to your computer whenever the button is pressed
  or released. This is how programmers "see inside" a running program.

  Wiring: same as sketch 02 (see ../02_button_pullup/schematic_2_button_pullup.png).

  To see the messages:
    - Arduino IDE: Tools > Serial Monitor (set the speed to 9600 baud)
    - Tinkercad: click "Serial Monitor" under the code window
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 13;

int lastState = HIGH;   // remember what the button was doing last time

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);   // start talking to the computer at 9600 baud
  Serial.println("Ready! Press the button.");
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  // Only print when something CHANGES, so we don't flood the screen
  if (state != lastState) {
    if (state == LOW) {
      Serial.println("Button: PRESSED");
    } else {
      Serial.println("Button: RELEASED");
    }
    lastState = state;
  }

  digitalWrite(LED_PIN, state == LOW ? HIGH : LOW);
}
