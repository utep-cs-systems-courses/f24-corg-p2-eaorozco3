.data
red_on:		.byte 0
green_on:	.byte 0
led_changed:	.byte 0
redVal:		.byte 0, .byte 1
greenVal:	.byte 0, .byte 64
	.text
	.global led_init
	.global led_update
	.extern P1DIR
	.extern LEDS
	.extern P1OUT
led_init:
	bis &LEDS, &P1DIR
	mov #1, led_changed
	call #led_update
led_update:
	cmp #0, led_changed
	jz Done
	mov red_on, r12
	mov r12(redVal), r12
	mov green_on, r13
	mov r13(greenVal), r13
	or r12, r13
	mov r13, r12
	mov 0xff, r13
	xor &LEDS, r13
	or r12, r13
	and r13, &P1OUT
	mov r13, r12
	mov #0, led_changed
Done:
	pop r0
	
		
