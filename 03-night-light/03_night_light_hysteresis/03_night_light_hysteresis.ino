/*
  03 - Night Light with Hysteresis
  Fixes a problem with sketch 02: when the room is right at the
  threshold, the reading wobbles up and down and the LED flickers.
  The fix is to use TWO thresholds, one to turn on and a different
  one to turn off.

  Wiring: same as sketch 02 (see ../02_night_light_basic/schematic_2_night_light.png).

    Reading drops BELOW 350  -> turn the LED on
    Reading rises  ABOVE 450 -> turn the LED off
    In between               -> do nothing (keep the current state)

  This "gap" is called hysteresis. Thermostats use the same trick.
*/

const int LDR_PIN = A0;
const int LED_PIN = 13;
const int TURN_ON_BELOW = 350;
const int TURN_OFF_ABOVE = 450;

bool ledOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int light = analogRead(LDR_PIN);

  if (!ledOn && light < TURN_ON_BELOW) {
    ledOn = true;
  } else if (ledOn && light > TURN_OFF_ABOVE) {
    ledOn = false;
  }

  digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
  delay(50);
}
