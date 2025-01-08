project('semitone', 'c', version: '0.1', default_options: ['warning_level=3'])

wiringpi = dependency('wiringPi')
fluidsynth = dependency('fluidsynth')
deps = [wiringpi, fluidsynth]

src_files = ['src/main.c', 'src/parse_notes.c', 'src/read_gpio.c', 'src/synth/synth.c']

install_data('SoundFonts/Piano.sf3')
install_data('SoundFonts/Bass1.sf2')
install_data('SoundFonts/Bass2.sf2')
install_data('SoundFonts/Drums.sf2')

executable('semitone', src_files, dependencies: deps, install: true)