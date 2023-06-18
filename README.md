Real-time Midi Microphone
=========================

Usage
-----

Plug it in to your computer and it will show up as a MIDI device.

Pick the device as the MIDI input for a virtual instrument.

Click the record button and whistle a tune. Don't blow directly into the microphone or you'll just get noise.

When you're done, clean up the roll manually, shift it up or down as desired, and apply any dynamics you want.

Parts List
----------

USB to Micro USB cable

Microphone Module [https://www.amazon.com/Gumps-grocery-Microphone-Sensitivity-Detecte/dp/B081YF381D]

Arduino Pro Micro (can be substituted for any board that uses the ATMega 32u4 proccessor)

Breadboard (if neccessary for your board)

Three jumper wires

Wiring
------

Microphone Out to Digital 5

Microphone power and ground to Arduino power and ground

Board
-----

Arduino Leonardo, Micro, Pro Micro, anything that uses the ATMega 32u4 proccessor.

You can just tell the IDE it's a Leonardo, and it should work.

Limitations
-----------

Requires very high signal to noise ratio, best results from whistling or whistle-based instruments (like a flute or recorder)

Makes a crude re-creation that you have to clean up manually.

How it works
------------

Time a few cycles of the wave  and take the average.

If timed out, release active note and end here.

Determine the frequency.

Take the log base two and multiply by 12.

Update the active note as needed.

Future Enhancements
-------------------

Button between 3 and GND for mute (single click) and switch between 12 and 24 tone (double click)
