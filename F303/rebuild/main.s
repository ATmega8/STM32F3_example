	.text
	.global main
	.code 16
	.syntax unified
	.type main, function

/*
 *¼Ä´æÆ÷µØÖ·¶¨Òå
 */
.equ PERIPH_BASE,            0x40000000
.equ AHB1PERIPH_BASE,        PERIPH_BASE + 0x00020000 
.equ AHB2PERIPH_BASE,        PERIPH_BASE + 0x08000000 
.equ RCC_BASE,               AHB1PERIPH_BASE + 0x00001000 
.equ GPIOE_BASE,             AHB2PERIPH_BASE + 0x1000 


/*
 *LED
 */

main:
	push		{r4, r5, lr}
	movs		r1, #1
	sub			sp, #12
	mov.w		r0, #2097152	
	mov.w		r4, #4096	
	bl			RCC_AHBPeriphClockCmd	
	movt		r4, #18432
	movs		r2, #1
	movs		r3, #0
	mov.w		r5, #32768
	mov			r0, r4
	mov			r1, sp
	strb.w		r2, [sp, #4]
	movs		r2, #3
	strb.w		r2, [sp, #5]
	strb.w		r3, [sp, #6]
	strb.w		r3, [sp, #7]
	str			r5, [sp, #0]
	bl			GPIO_Init
	mov			r1, r5
	mov			r0, r4
	bl			GPIO_ReadOutputDataBit 
	rsb			r2, r0, #1
	mov			r1, r5
	mov			r0, r4
	uxtb		r2, r2
	bl			GPIO_WriteBit
	add			sp, #12
	pop			{r4, r5, pc}

deadloop:
	b	deadloop

	.end
