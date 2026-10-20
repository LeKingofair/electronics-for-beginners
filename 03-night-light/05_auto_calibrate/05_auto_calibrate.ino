/*
  05 - Auto-Calibrating Night Light
  Every room and every photoresistor is different. Instead of guessing
  numbers, this sketch measures them for you at startup.

  Wiring: same as sketch 04 (see ../04_night_light_dimmer/schematic_3_dimmable_night_light.png).

  How to use it:
    1. Power on. The LED lights up for 5 seconds = calibration time.
    2. During those 5 seconds, cover the sensor with your hand, then
       shine a light on it (or move it into a bright spot).
    3. The LED turns off and the night light starts working, using the
       darkest and brightest readings it just saw.
*/

const int LDR_PIN = A0;
const int LED_PIN = 9;
const unsigned long CALIBRATION_MS = 5000;

int lightMin = 1023;   // start high so any reading is lower
int lightMax = 0;      // start low so any reading is higher

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH);   // LED on = "calibrating"
  unsigned long start = millis();

  while (millis() - start < CALIBRATION_MS) {
    int reading = analogRead(LDR_PIN);
    if (reading < lightMin) lightMin = reading;
    if (reading > lightMax) lightMax = reading;
  }

  // Avoid dividing by zero later if the light never changed
  if (lightMax - lightMin < 10) {
    lightMax = lightMin + 10;
  }

  digitalWrite(LED_PIN, LOW);

  Serial.print("Darkest: ");
  Serial.print(lightMin);
  Serial.print("   Brightest: ");
  Serial.println(lightMax);
}

void loop() {
  int light = analogRead(LDR_PIN);

  int brightness = map(light, lightMin, lightMax, 255, 0);
  brightness = constrain(brightness, 0, 255);

  analogWrite(LED_PIN, brightness);
  delay(10);
}
