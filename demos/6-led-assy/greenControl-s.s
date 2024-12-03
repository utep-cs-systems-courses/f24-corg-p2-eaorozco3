	.arch msp430g2553
	.p2align 1,0
	.text


	.global greenControl
	.extern P1OUT

greenControl:
	cmp #0, r12
	jz off
	bis #64, &P1OUT		;or
	pop r0
off:	and #~64, &P1OUT
	pop r0


	.data
	.align 4
	.global blinkLimit
blinkLimit:	.long 5

	.text
	.global blinkUpdate
blinkUpdate:
	sub #2, r1
	mov #0, 0(r1)
	add #1, 0(r1)
	mov blinkLimit, r13
	cmp r13, 0(r1)
	jge else
	mov #0, 0(r1)
	mov #1, r12
	call greenControl
	pop r0
else:
	mov #0, r12
	call greenControl
	pop r0
