/*
  04 - Button Toggle (with debounce)
  Press once: LED turns ON and STAYS on.
  Press again: LED turns OFF. Like a light switch.

  Wiring: same as sketch 02 (see ../02_button_pullup/schematic_2_button_pullup.png).

  What is "debounce"?
    A real button doesn't switch cleanly. For a few milliseconds it
    flickers on and off ("bounces"). Without handling that, one press
    could toggle the LED several times. We ignore changes until the
    reading has stayed the same for 50 ms.
*/

const int BUTTON_PIN = 2;
const int LED_PIN = 13;
const unsigned long DEBOUNCE_MS = 50;

bool ledOn = false;               // is the LED currently on?
int lastReading = HIGH;           // last raw reading from the pin
int stableState = HIGH;           // last reading we trust
unsigned long lastChangeTime = 0; // when the raw reading last changed

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // The raw reading changed: restart the timer
  if (reading != lastReading) {
    lastChangeTime = millis();
  }

  // The reading has been steady long enough to trust it
  if ((millis() - lastChangeTime) > DEBOUNCE_MS) {
    if (reading != stableState) {
      stableState = reading;

      // Toggle only on the press (HIGH -> LOW), not on release
      if (stableState == LOW) {
        ledOn = !ledOn;
        digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
      }
    }
  }

  lastReading = reading;
}
