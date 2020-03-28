; ft_strdup

	segment .text
	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	cmp 	rdi, 0
	je		error		; check if 1st argument exist
	call 	_ft_strlen	; get string len in rax
	inc 	rax			; increment rax for last 0
	push	rdi			; mov 1st arg to the stack
	mov		rdi, rax	
	call	_malloc		; malloc size of rdi 
	cmp		rax, 0
	je		error
	pop		rdi			; rdi back from the stack
	push	rsi			
	mov 	rsi, rdi	; mov the string we want to copy in rsi(src fo strcpy)
	mov		rdi, rax	; mov the string malloc(ed) in rdi before the copy
	call	_ft_strcpy	; return the string copied (in rax)
	pop		rsi
	ret
	
error:
	mov rax, 0
	ret
