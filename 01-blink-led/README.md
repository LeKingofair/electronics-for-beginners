# Project 01: Blink LED

Your first circuit. You'll make one LED blink, then build up to multiple LEDs running different patterns.

**Time:** 30-60 minutes | **Difficulty:** Beginner | **Cost:** about $5 for real parts (free in Tinkercad)

## What You'll Learn

- How to wire an LED and why it needs a resistor
- Setting a pin as an output with `pinMode()`
- Turning a pin on and off with `digitalWrite()`
- Timing with `delay()`
- Variables, `for` loops and arrays to make your code shorter

## Parts List

| Part | Qty | Approx. cost |
|------|-----|--------------|
| Arduino Uno | 1 | $10-28 (clones are cheaper) |
| Breadboard | 1 | $3 |
| LEDs (any color) | 4 | $1 |
| 220 Ω resistors | 4 | $1 |
| Jumper wires | ~10 | $3 |

In Tinkercad, search for these in the Components panel.

## Wiring

### Single LED (sketches 01-02)

```
Arduino pin 13 --> 220 Ω resistor --> LED long leg (anode, +)
LED short leg (cathode, -) --> Arduino GND
```

> **Tip:** The long leg of an LED is positive (+). The short leg is negative (-). If your LED doesn't light up, flip it around.

### Multiple LEDs (sketches 03-08)

Each LED gets its **own** resistor. Wire them the same way as above, using these pins:

| LED | Arduino pin |
|-----|-------------|
| LED 1 | 8 |
| LED 2 | 9 |
| LED 3 | 10 |
| LED 4 | 11 |

All the short legs (cathodes) connect to GND through the breadboard's ground rail.

<!-- Add Tinkercad screenshots here: images/single-led.png and images/four-leds.png -->

## The Sketches

Do these in order. Each one builds on the last.

| File | What it does | New idea |
|------|--------------|----------|
| [`01_blink_basic`](01_blink_basic/01_blink_basic.ino) | One LED, on for 1 second, off for 1 second | `pinMode`, `digitalWrite`, `delay` |
| [`02_blink_variables`](02_blink_variables/02_blink_variables.ino) | Same thing, but easy to change speed | Variables and constants |
| [`03_two_led_alternate`](03_two_led_alternate/03_two_led_alternate.ino) | Two LEDs take turns | Controlling more than one pin |
| [`04_traffic_light`](04_traffic_light/04_traffic_light.ino) | Green, yellow, red cycle | Sequences with different timings |
| [`05_chase`](05_chase/05_chase.ino) | Light "runs" across 4 LEDs | Arrays and `for` loops |
| [`06_knight_rider`](06_knight_rider/06_knight_rider.ino) | Light bounces back and forth | Looping forward and backward |
| [`07_binary_counter`](07_binary_counter/07_binary_counter.ino) | LEDs count from 0 to 15 in binary | Bits, `bitRead()` |
| [`08_random_twinkle`](08_random_twinkle/08_random_twinkle.ino) | LEDs flash randomly | `random()` |

(Each sketch is in its own folder because the Arduino IDE requires the folder name to match the file name.)

## How to Run in Tinkercad

1. Go to Tinkercad, then **Circuits**, then **Create new Circuit**.
2. Add an Arduino Uno, a breadboard, LEDs and resistors.
3. Wire it up using the tables above.
4. Click **Code**, switch to **Text** mode, and paste in a sketch.
5. Click **Start Simulation**.

## Common Mistakes

- **LED doesn't light:** it's probably backwards. Flip it so the long leg goes toward the resistor/pin side.
- **No resistor:** the LED can burn out in real life. Always use one (220 Ω is a safe choice).
- **Nothing happens:** check that the pin number in the code matches the pin you wired to.
- **One LED always on:** make sure each LED has its own connection to its pin, and that the ground wire is connected.
- **Upload fails (real board):** pick the right board and port under **Tools** in the Arduino IDE.

## Challenges

Once you've finished all eight, try these:

1. Make the single LED blink twice as fast without editing the `delay()` numbers directly. (Hint: sketch 02.)
2. Make the 4-LED chase go in the opposite direction.
3. Make an LED "heartbeat": two quick blinks, then a pause.
4. Add a fifth LED on pin 12 and update the code to use it.
5. Make your own pattern and add it to this repo as `09_your_name_here`.

## Next Project

Now that you can control an LED, the next step is controlling it with a **button**. Coming soon in Project 02.
