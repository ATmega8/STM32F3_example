	.cpu cortex-m0
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.code	16
	.file	"main.c"
	.global	a
	.data
	.align	3
	.type	a, %object
	.size	a, 8
a:
	.word	-1
	.word	0
	.global	b
	.align	3
	.type	b, %object
	.size	b, 8
b:
	.word	-1
	.word	0
	.comm	c,8,8
	.global	__aeabi_lmul
	.text
	.align	2
	.global	main
	.code	16
	.thumb_func
	.type	main, %function
main:
	push	{r3, r4, r7, lr}
	add	r7, sp, #0
	ldr	r3, .L2
	ldr	r1, [r3]
	ldr	r2, [r3, #4]
	ldr	r3, .L2+4
	ldr	r4, [r3, #4]
	ldr	r3, [r3]
	mov	r0, r1
	mov	r1, r2
	mov	r2, r3
	mov	r3, r4
	bl	__aeabi_lmul
	mov	r3, r0
	mov	r4, r1
	ldr	r2, .L2+8
	str	r3, [r2]
	str	r4, [r2, #4]
	mov	r0, r3
	mov	sp, r7
	@ sp needed for prologue
	pop	{r3, r4, r7, pc}
.L3:
	.align	2
.L2:
	.word	a
	.word	b
	.word	c
	.size	main, .-main
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 4.7.4 20130613 (release) [ARM/embedded-4_7-branch revision 200083]"
