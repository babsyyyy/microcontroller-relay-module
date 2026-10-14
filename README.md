# Microcontroller-Controlled Relay Module

A custom relay-control circuit built during my electronics internship to explore optocoupler isolation, transistor switching, and practical hardware troubleshooting.

> **Documentation note:** The original source code and circuit drawing were not retained. This repository contains a recreated Arduino test sketch and reconstructed circuit notes based on the parts and behavior remembered from the project. Details that could not be confirmed are marked as unverified.

## Project overview

The goal was to control a 5 V relay from a microcontroller without driving the relay coil directly from a GPIO pin. The circuit used a PC817 optocoupler between the control input and relay-driving stage, with a 2N2222 NPN transistor switching the relay coil.

The remembered functional path was:
1. Arduino digital pin 8 drove the PC817 input LED through a current-limiting resistor.
2. The PC817 transferred the control signal optically to the relay-driving side.
3. The optocoupler output drove the base of a 2N2222 through a resistor recalled as 1 kΩ.
4. The transistor switched current through the 5 V relay coil.
5. A flyback diode across the coil protected the switching transistor from inductive voltage spikes.

## Components

| Component | Role / details |
|---|---|
| Arduino-compatible microcontroller | Control output; pin 8 in the recreated sketch |
| PC817 optocoupler | Signal transfer and isolation |
| 2N2222 NPN transistor | Relay coil driver |
| Electromechanical relay | 5 V coil |
| Input resistor | Limits PC817 LED current; exact original value not confirmed |
| Base resistor | Recalled as 1 kΩ between the optocoupler output stage and transistor base |
| Flyback diode | Across the relay coil; exact original part number not confirmed |
| Separate 5 V supply | Powers the relay-driving side |

## Arduino test sketch

The original program simply set a digital pin HIGH to activate the PC817 input LED. The recreated sketch is in [`code/relay_test.ino`](code/relay_test.ino).

It is only a basic activation test; it does not implement timing, user input, or a full relay-control system.

## Circuit operation

### Control side
Arduino digital pin 8 connects through a current-limiting resistor to the PC817 input LED. The LED's other terminal returns to Arduino GND. When pin 8 is HIGH, current flows through the LED if the resistor and wiring are appropriate.

### Relay-driving side
A separate 5 V supply powers the relay-driving side and 5 V relay circuit. The PC817 output stage drives the 2N2222 base through a resistor, and the transistor switches the relay coil. A flyback diode should be placed across the coil with its cathode toward the positive coil supply and its anode toward the transistor/low side.

**Important:** The exact PC817 output-pin connections, input resistor value, diode part number, and original transistor wiring could not be independently verified. Read [`docs/circuit-notes.md`](docs/circuit-notes.md) before using the reconstructed topology as a wiring guide.

## The challenge and what I learned

One of the main challenges was assuming the optocoupler output would provide everything needed to drive the transistor and relay without a separate supply on that side. Troubleshooting helped clarify that an optocoupler transfers a signal; it is not a power source. The relay coil and transistor driver still need a suitable supply and correctly designed current paths.

The project reinforced the importance of:
- keeping the control and load-driving stages conceptually separate;
- checking the relay coil's rated voltage and current;
- selecting appropriate input and base resistors;
- checking PC817 and transistor pinouts against datasheets;
- adding a flyback diode across an inductive relay coil; and
- tracing the circuit stage by stage instead of assuming a HIGH GPIO signal guarantees relay operation.

## Repository contents

- [`code/relay_test.ino`](code/relay_test.ino) — recreated Arduino output test.
- [`docs/circuit-notes.md`](docs/circuit-notes.md) — reconstructed topology and verification cautions.
- [`docs/troubleshooting.md`](docs/troubleshooting.md) — troubleshooting notes and lessons learned.

## Status and limitations

This is a learning-project record, not a verified production design. The original prototype is no longer available for measurement, and the original source code and schematic could not be found. Before rebuilding the circuit, verify all pinouts, resistor values, supply connections, coil current, diode orientation, and isolation boundaries against the actual component datasheets.

## Possible improvements

- Draw and verify the final schematic against the physical circuit.
- Record exact component values and part numbers.
- Add a status LED or a controlled on/off test.
- Measure and document voltages and relay coil current.
- Design a compact PCB after validating the circuit.

---

Built and documented as part of an electronics internship, with the focus on learning through construction and troubleshooting.
