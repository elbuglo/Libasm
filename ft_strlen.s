;ft_strlen.s
	segment .text
    global _ft_strlen

_ft_strlen:
    mov     rax, 0	; initialize rax to 0
    jmp     count	; start counting

count:
    cmp     BYTE [rdi + rax], 0	
	; compare the value byte in rax pos of the first argument(rdi)   
    je      exit	; if equal, exit
    inc     rax		; increment the value of rax by one
    jmp     count 	; loop counting

exit:
    ret				; return the address of rax(the return register)
