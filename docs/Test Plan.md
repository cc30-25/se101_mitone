# Test Plan

## Automated

Because the functionality of the keyboard is so tightly coupled to the physical buttons and the media output, developing automated tests for it is beyond the scope of this project.

If the project were to be developed further in the future, a possible approach could be to develop a physical test apparatus which mimicks the manual tests described below, then develop a custom PipeWire media sink to read the audio output from the software and analyze it with a Fast Fourier Transform to ensure that the proper notes are being played.

## Manual

All tests for the product will be performed manually.

Testing and quality assurance procedures will be carried out manually as follows. If any step fails, identify the issue before proceeding to the next step:

1. Connect Raspberry Pi to a power source and connect to it over SSH.
2. Pair it with a Bluetooth speaker using `bluetoothctl` and test the speaker with the `speaker-test` command line utility.
3. Launch `semitone` with a path to a SoundFont file as a command-line argument and wait for the message `Semitone loaded!` to be printed.
4. Play a full chromatic scale on the keyboard, first in whole notes, then repeated eighth notes.
5. Play a C major chord, augmented fourth from D# to A, and inverted B minor chord.
6. Repeat steps 3-5 with at least two distinct SoundFont files.
