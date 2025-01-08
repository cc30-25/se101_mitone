#ifndef SYNTH_H
#define SYNTH_H

#include "note.h"

typedef struct synth synth;
synth *init_synth(char *sf_data_path);
void destroy_synth(synth *synth_object);

void noteOn(note n, synth *synth_object);

void noteOff(note n, synth *synth_object);

#endif