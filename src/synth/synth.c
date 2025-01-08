#include "synth.h"
#include <fluidsynth.h>
#include <stdlib.h>
#include <stdio.h>

struct synth
{
    fluid_settings_t *settings;
    fluid_synth_t *synth;
    fluid_audio_driver_t *adriver;
};

synth *init_synth(char *sf_data_path)
{
    synth *synth_new = malloc(sizeof(synth));
    fluid_settings_t *settings = new_fluid_settings();
    if (!settings)
    {
        fprintf(stderr, "Failed to initialize FluidSynth settings\n");
        destroy_synth(synth_new);
        return NULL;
    }
    synth_new->settings = settings;

    fluid_synth_t *fl_synth = new_fluid_synth(settings);
    if (!fl_synth)
    {
        fprintf(stderr, "Failed to initialize FluidSynth synthesizer\n");
        destroy_synth(synth_new);
        return NULL;
    }
    synth_new->synth = fl_synth;

    fluid_audio_driver_t *adriver = new_fluid_audio_driver(settings, fl_synth);
    if (!adriver)
    {
        fprintf(stderr, "Failed to initialize FluidSynth synthesizer\n");
        destroy_synth(synth_new);
        return NULL;
    }
    synth_new->adriver = adriver;

    // Load soundfont and select Grand Piano preset
    int sfont_id = fluid_synth_sfload(fl_synth, sf_data_path, 1);
    if (sfont_id == FLUID_FAILED)
    {
        fprintf(stderr, "Failed to load SoundFont\n");
        destroy_synth(synth_new);
        return NULL;
    }
    fluid_synth_program_select(fl_synth, 0, sfont_id, 0, 0);

    // Set volume to maximum
    fluid_synth_cc(fl_synth, 0, 7, 127);
    fluid_settings_setnum(settings, "synth.gain", 10.0);

    return synth_new;
}

void destroy_synth(synth *synth_object)
{
    if (synth_object->synth)
        delete_fluid_synth(synth_object->synth);
    if (synth_object->settings)
        delete_fluid_settings(synth_object->settings);
    if (synth_object->adriver)
        delete_fluid_audio_driver(synth_object->adriver);
    free(synth_object);
}

void noteOn(note n, synth *synth_object)
{
    fluid_synth_noteon(synth_object->synth, 0, n.noteID, 75);
}

void noteOff(note n, synth *synth_object)
{
    fluid_synth_noteoff(synth_object->synth, 0, n.noteID);
}
