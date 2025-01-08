#include "synth/synth.h"

#ifndef READ_GPIO_H
#define READ_GPIO_H

// Registers handlers for button press/release events which turn notes on and off via the synthesizer interface.
void init_gpio_handlers(synth *synth_object);

#endif // READ_GPIO_H