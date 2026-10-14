# Reconstructed circuit notes

This document records the circuit topology recalled from the project. It is **not a verified pin-by-pin schematic** because the original prototype and drawing are unavailable.

## Functional blocks

```text
CONTROL SIDE                              RELAY-DRIVING SIDE
Arduino                                  Separate regulated 5 V supply
D8 -- current-limiting resistor --> PC817 input LED
GND -------------------------------> PC817 input LED return

                    optical isolation barrier

                                  PC817 phototransistor output
                                             |
                                      1 kΩ base resistor
                                             |
                                        2N2222 base
                                             |
5 V supply ------------- relay coil ----- 2N2222 collector
                                             |
                                        2N2222 emitter
                                             |
                                      relay-side supply GND

Flyback diode across the relay coil:
- Cathode toward the positive 5 V coil supply.
- Anode toward the transistor/low-side end of the coil.
```

This block diagram shows intended functions and current paths, not the exact original pin connections. The PC817 output can be wired in different ways, and the correct topology depends on how its collector and emitter were connected. Verify the PC817 pinout and transistor base drive before rebuilding.

## Recalled project details

- Arduino pin 8 was driven HIGH.
- A resistor was placed between the Arduino output and PC817 input LED.
- The optocoupler output stage connected toward the 2N2222 transistor base through a 1 kΩ resistor.
- The relay coil was rated for 5 V.
- A separate 5 V supply powered the relay-driving side.
- A flyback diode was part of the intended relay-driver circuit.

## Still unverified

- Exact input resistor value.
- Exact diode part number and original orientation.
- Exact PC817 output collector/emitter connections.
- Exact 2N2222 pinout for the specific package and manufacturer.
- Whether the prototype kept the control and relay-side grounds fully separate.

## Isolation and safety notes

For galvanic isolation, do not connect Arduino GND to relay-side GND across the optocoupler barrier. Use a separate relay-side supply and keep the two sides electrically separate. If the original circuit tied the grounds together, it would not provide full galvanic isolation.

Use a low-voltage test load while validating the circuit. Do not connect mains voltage to an unverified prototype.
