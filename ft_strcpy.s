; ft_strcpy

	segment .text
	global ft_strcpy

ft_strcpy:
	mov	rax, 0
	jmp	copy

copy:
	cmp	BYTE[rsi + rax], 0 ; check if we reached the end of the 2nd arg 
	je	EXIT	; if so, exit and return
	mov BYTE[rdi + rax], BYTE[rsi + rax] ; Copy the n byte of the 2nd arg to the first
	inc	rax	; increment rda
	jmp	copy

EXIT:
	mov rax, rdi
	ret