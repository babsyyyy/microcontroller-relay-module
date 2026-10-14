# Troubleshooting and lessons learned

## Initial challenge

The first assumption was that the PC817 output would provide enough drive for the transistor and relay without a separate supply on the relay-driving side. The project helped clarify that the relay side needs its own suitable 5 V supply and a correctly wired transistor driver.

## Suggested checks for a future rebuild

1. **Arduino output:** Confirm pin 8 goes HIGH and measure it relative to Arduino GND.
2. **PC817 input:** Verify LED polarity and the series resistor. Calculate LED current using the supply voltage, LED forward voltage, and resistor value.
3. **Optocoupler output:** Verify the PC817 pinout from its datasheet and check the output-stage behavior with the intended relay-side supply.
4. **Transistor driver:** Confirm the 2N2222 pinout for the exact package/manufacturer. Check base resistor placement and ensure the transistor can handle the coil current.
5. **Relay coil:** Confirm the relay is rated for 5 V and the supply can provide the required coil current.
6. **Flyback diode:** Confirm it is across the coil in reverse bias during normal energization (cathode to +5 V).
7. **Isolation:** Keep control-side and relay-side grounds separate if galvanic isolation is required.

## Lessons learned

- An optocoupler transfers a control signal; it is not a power supply.
- A relay coil needs a supply with sufficient voltage and current.
- Resistor values and transistor pinouts should be checked rather than guessed.
- A flyback diode protects the switching transistor from the relay coil's inductive voltage spike.
- A HIGH microcontroller output alone does not prove that the complete driver circuit is correct.

## Record accuracy

These notes were recreated from memory after the original code and hardware were no longer available. They describe the remembered challenge and intended architecture, not measured results from a new test.
