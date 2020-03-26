; ft_strcpy

	segment .text
	global _ft_strcpy

_ft_strcpy:
	xor	rcx, rcx 
	xor rdx, rdx
	cmp rsi, 0 ; check if src exist
	jz return	; jump to return if bits(src or rsi) are not set(zeros)
	jmp	copy

increment:
	inc	rcx

copy:
	mov dl, BYTE [rsi + rcx] ; copy src dans temp
	mov BYTE [rdi + rcx], dl ; copy tmp dans dest
	cmp	dl, 0
	jnz increment	; jump to inc if dl(8 lowest bits) are set(not zeros) 

return:
	mov rax, rdi ; return dest
	ret
