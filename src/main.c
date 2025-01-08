#include "read_gpio.h"
#include <unistd.h>
#include "synth/synth.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    synth *synth = init_synth(argv[1]);
    init_gpio_handlers(synth);
    printf("Semitone loading complete!\n");
    while (1)
        sleep(1);
    destroy_synth(synth);
    return 0;
}
