# GPIO Handling

## Overview

The program gets its input from the GPIO (General-Purpose Input-Output) pins on the Raspberry Pi.

The buttons are connected to the pins such that when the buttons are pushed down, it completes a circuit and the pins will get an electrical current.
When the buttons are released, the circuit is broken and the pins stop receiving the signal.

The files `read_gpio.h/.c` contain the code which reads the signals from the pins and triggers functions to play the notes based on that input.

## Implementation Details

The GPIO library being used, WiringPi, allows us to run a custom function every time the GPIO pin switches from off to on, or vice versa.

The custom function must be of type `void fn(void)`, so they have no parameter indicating which pin was just pressed.
To get around this, `read_gpio.c` uses what's called "macro": essentially, code which writes code.

The internal macros `PIN_HANDLER_FUNCTION` and `HANDLE_PIN` create a separate function for each note, which have the index of the pin hard-coded into them to get around the fact that it's not available as a parameter.

Inside these custom functions, the index of the pin gets converted into a `note` object, which is then passed to the synthesizer to get played as music.

## Possible Improvements

- Adding an octave key to the keyboard would double its musical range. This would require adding another GPIO handler for the octave key which switches which octave is being sent to the `convert` function.
