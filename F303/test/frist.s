/*L. 2013-06-03 ±‡“Î∆˜≤‚ ‘*/

	.text
	.code 16
	.syntax unified
	.global main
	.global SystemInit

	.type SystemInit, function


SystemInit:
	.type main, function

main:
	movs	r0,	#10
	movs	r1,	#0

loop:
	adds	r1,	r0
	subs	r0,	#1
	bne	loop

deadloop:
	b	deadloop

	.end
	
