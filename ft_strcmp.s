; ft_strcmp

	segment .text
	global ft_strcmp

ft_strcmp:
	xor	rdx, rdx
	xor rcx, rcx
	mov rcx, -1
	jmp increment

compare:
	mov	dl, BYTE [rsi + rcx]	; tmp = s2[i]
	cmp	BYTE [rdi + rcx], dl	; compare tmp and s1[i]
	jne	end						; if not equal jump to end

increment:
	inc	rcx
	cmp	BYTE [rdi + rcx], 0		
	je	end						; if s1[i] equal 0
	cmp	BYTE [rsi + rcx], 0		
	je	end						; if s2[i] equal 0
	jmp	compare

end:
	mov	dl, BYTE [rdi + rcx]	; tmp = s1[i]
	sub	dl, BYTE [rsi + rcx]	; tmp -= s2[i]
	cmp	dl, 0
	jz	equal					; if tmp == 0 
	jl	inferior				; if tmp < 0

superior:
	mov rax, 1
	ret

inferior:
	mov rax, -1
	ret

equal:
	mov rax, 0
	ret
