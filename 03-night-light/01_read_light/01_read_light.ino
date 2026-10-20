/*
  01 - Read Light
  Reads a photoresistor (LDR) and prints the light level to the
  Serial Monitor. Run this first to find out what numbers YOUR room gives.

  Wiring (see schematic_1_ldr_divider.png in this folder):
    5V -> photoresistor -> pin A0
    Pin A0 -> 10k ohm resistor -> GND

  How it works:
    The photoresistor changes its resistance with light.
      Bright light = low resistance  = higher voltage at A0
      Darkness     = high resistance = lower voltage at A0
    analogRead() turns that voltage into a number from 0 to 1023:
      0 = 0 volts, 1023 = 5 volts.

  To see the numbers:
    - Arduino IDE: Tools > Serial Monitor (9600 baud)
    - Tinkercad: click "Serial Monitor", then click the photoresistor
      in the simulator and drag the light slider.
*/

const int LDR_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);               // 0 to 1023
  float volts = light * (5.0 / 1023.0);          // convert to volts

  Serial.print("Light level: ");
  Serial.print(light);
  Serial.print("   Voltage: ");
  Serial.print(volts);
  Serial.println(" V");

  delay(300);   // slow down so the numbers are readable
}
