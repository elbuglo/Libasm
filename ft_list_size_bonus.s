; ft_list_size

	segment .text
	global	ft_list_size

ft_list_size:
	xor	rax, rax
	mov rsi, rdi	; copy the adress of the list's beginning in rsi
	jmp	size

size:
	cmp rdi, 0				; no adress so end of list
	je	return
	mov rdi, [rdi + 8]	; list = list->next
	inc	rax
	jmp size


return:
	mov rdi, rsi
	ret