	.arch msp430g2553
	.text
	.extern firstSw_transition
	.global first_transition
	.global second_transition
	.global third_transition
	.global fourth_transition

first_transition:
	cmp #2, &firstSw_transition
	jnc resetOne
	add.b #1, &firstSw_transition
	pop r0
resetOne:
	mov.b #1, &firstSw_transition
	pop r0

second_transition:
	cmp #3, &secondSw_transition
	jnc resetTwo
	add.b #1, &secondSw_transition
	pop r0
resetTwo:
	mov.b #1, secondSw_transition
	pop r0
	
third_transition:
	cmp #3, &thirdSw_transition
	jnc resetThree
	add.b #1, &thirdSw_transition
	pop r0
resetThree:
	mov.b #1, &thirdSw_transition
	pop r0
	
fourth_transition:
	cmp #7, &fourthSw_transition
	jnc resetFour
	add.b #1, &fourthSw_transition
	pop r0
resetFour:
	mov.b #1, &fourthSw_transition
	pop r0
