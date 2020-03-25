; ; ft_strcpy

; 	segment .text
; 	global ft_strcpy

; ft_strcpy:
; 	xor	rcx, rcx
; 	xor rdx, rdx	; initialize rdx
; 	cmp rsi, 0 ; check if dest src exist
; 	jz return
; 	jmp	copy

; increment:
; 	inc	rcx

; copy:
; 	mov dl, BYTE [rsi + rcx]
; 	mov BYTE [rdi + rcx], dl
; 	cmp	dl, 0
; 	jnz increment

; return:
; 	mov rax, rdi
; 	ret

; ft_strcpy

	segment .text
	global ft_strcpy

ft_strcpy:
	xor	rcx, rcx
	xor rdx, rdx	; initialize rdx
	cmp rsi, 0 ; check if dest src exist
	jz return
	jmp	copy

copy:
	mov dl, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], dl
	cmp	dl, 0
	jnz increment

return:
	mov rax, rdi
	ret