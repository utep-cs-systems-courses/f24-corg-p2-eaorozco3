Lab 2: Blinky-Buzzy-Toy
by Emilio Orozco:

   This project was completed using an MSP430 and inspired by various demos
   included in this directory, each containing different functionalities.


How to compile the toy?
    There are two ways to compile the toy. The first way is to use the command
    "make toy-c.elf", which will use the C compiler to compile the main file and
    other file necessities. The second way to compile this toy is to use "make
    toy-s.elf", which will compile the toy using the assembly compiler. The only
    real difference is that the latter uses assembly code to transition
    between states when the buttons are pressed.

How to run the toy?
    First compile the toy using the desired compiler, then either run "make
    load-c" if compiled using the C compiler, and "make load-s" if using the
    assembly compiler. This will run the toy and load the instructions onto
    the MSP430.

How to use the toy?
    The toy has various functionalities, each bound by the four buttons
    provided by the MSP430's display board. Each button is tasked to do
    something while maintaining specific states:

    Button 1:
    The LEDS will turn on and off following a specific sequence.
    
    	State 1:
	If the button is pressed once, the lights will play a
    	sequence that resembles the "Asgore" soundtrack theme from the videogame
    	"Undertale".
	
	State 2:
	If the button is pressed a second time, the lights will turn
    	off. If pressed once more, return to state 1.

     Button 2:
     A combination of lights and sound will follow a specific sequence.

       	State 1:
	If the button is pressed once, sound will be produced in an attempt to
	reproduce five seconds of the "Asgore" soundtrack theme from the
	videogame "Undertale". Once the five seconds occur, the sound will
	loop to the start.

	State 2:
	If the button is pressed twice, both sound and lights will attempt to
	reproduce five seconds of the "Asgore" soundtrack theme. Both will
	also loop every five seconds. Pressing the button after this will
	return to state 1.

     Button 3:
     Lights and sounds will be controlled by button presses.

        State 1:
	If the button is pressed once, the green LED will be turned on and a
	sound will be played.

	State 2:
	If the button is pressed twice, the red LED will turn on and a sound
	will be played.

	State 3:
	Both the lights and the speakers will be turned off. If pressed once
	more, return to state 1.

     Button 4:
     Lights and sounds will be manipulated so that they blink in varying
     patterns.

         State 1:
	 The green LED will blink from bright to dim. Sound will also play
	 from high to low frequency.

	 State 2:
	 The green LED will blink from dim to bright. Sound will also play
	 from low to high frequency.

	 State 3:
	 The red LED will blink from bright to dim. Sound will also play from
	 high to low frequency.

	 State 4:
	 The red LED will blink from dim to bright. Sound will also play from
	 low to high frequency.

	 State 5:
	 Both LEDS will blink from bright to dim. Sound will also play from
	 high to low frequency.

	 State 6:
	 Both LEDs will blink from dim to bright. Sound will also play from
	 low to high frequency.

	 State 7:
	 Both LEDs will turn off and any sound will also be turned
	 off. Pressing the button again will return to state 1.

	 The user is also free to go from button 2 state 1 to button 4 state 3
	 if they so desire. The state of each button will be saved so any
	 further button presses will resume from where they left off.



