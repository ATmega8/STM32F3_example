	.text
	.global _start
	.global nmi_handler
	.global main
	.global SystemInit
	.syntax unified
	.type main , function
	.type nmi_handler, function

main:
	movs	r0,	#10
	movs	r1,	#0

SystemInit:
	ldr r3, = 0x12345678
loop:
	adds	r1,	r0
	subs	r0,	#1
	bne	loop

deadloop:
	b	deadloop

nmi_handler:
	bx	lr

	.end
