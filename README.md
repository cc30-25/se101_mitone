# SE-mitone

Musical keyboard software for the Raspberry Pi Zero W.

## Repository Structure

Detailed technical documentation is located in the `docs/` subfolder, while the C code is located under `src/`.

## Dependencies

The following packages must be installed on the system in order to build and run the code:

- [WiringPi](https://github.com/WiringPi/WiringPi)
- [FluidSynth](https://github.com/FluidSynth/fluidsynth)

## Compiling

SE-mitone uses the Meson build system.

To setup up the build environment, run `meson setup builddir` from the repository root.

Then run `cd builddir && meson compile` to compile the code. The resulting executable will be located at `builddir/semitone`.