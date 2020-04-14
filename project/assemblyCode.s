	.arch msp430g2553
	.p2align 1,0
	.data
jt:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global switch_state_call

switch_state_call:
	cmp #5, r12
	jc default
	add r12,r12
	mov jt(r12),r0
case1:
	call #playPokemonTheme
	jmp end
case2:
	call #playMarioTheme
	jmp end
case3:
	call #playRememberMe
	jmp end
case4:
	call #playMarioTheme
	jmp end
default:
	jmp end
end:
	ret
