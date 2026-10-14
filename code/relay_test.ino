/*
  Microcontroller-Controlled Relay Module
  Recreated Arduino test sketch.

  Purpose:
  Drive digital pin 8 HIGH to activate the PC817 optocoupler input LED
  through a current-limiting resistor.

  NOTE:
  This is a reconstruction of the simple test program, not the original
  source file. Confirm the physical wiring and resistor value before use.
*/

const int optocouplerPin = 8;

void setup() {
  pinMode(optocouplerPin, OUTPUT);
  digitalWrite(optocouplerPin, HIGH);
}

void loop() {
  // The output remains HIGH. No repeated action is required.
}
