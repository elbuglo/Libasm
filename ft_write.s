; ft_write

	segment .text
	global	_ft_write

_ft_write:
	push 	r8
	push	r9
	cmp		rsi, 0
	jz		error
	mov 	r8, rsi 		; save parameters before fstat
	mov 	r9, rdx
	mov 	rsi, 0x0 		; fstat getting buf as second parameter
	mov 	rax, 0x20000BD	; 0xBD --> fstat syscall
	syscall
	cmp 	rax, 9 			; if fstat return 9 it's errno 9 so badfd
	jz 		error
	mov 	rsi, r8 		; saved parameters
	mov 	rdx, r9
	mov		rax, 0x2000004
	syscall
	pop 	r8
	pop 	r9
	ret

error:
	mov	rax, -1
	pop r8
	pop	r9
	ret