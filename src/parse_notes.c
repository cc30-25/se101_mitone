#include "parse_notes.h"

note convert(int index, int octave)
{
    note n = {(octave * 12) + index};
    return n;
}