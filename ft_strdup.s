; ft_strdup

	segment .text
	global	ft_strdup
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

ft_strdup:
	cmp 	rdi, 0
	je		error
	call 	ft_strlen
	inc 	rax
	push	rdi
	mov		rdi, rax
	call	malloc
	cmp		rax, 0
	je		error
	pop		rdi
	push	rsi
	mov 	rsi, rdi
	mov		rdi, rax
	call	ft_strcpy
	pop		rsi
	ret
	
error:
	mov rax, 0
	ret