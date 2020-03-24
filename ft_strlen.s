;ft_strlen.s
	segment .text
    global ft_strlen

ft_strlen:
    mov     rax, 0	; initialize rax to 0
    jmp     count	; start counting

count:
    cmp     BYTE [rdi + rax], 0	
	; compare the value byte in rax pos of the first argument(rdi)   
    je      exit	; if rdi + rax == 0, go to exit
    inc     rax		; increment the value of rax by one
    jmp     count 	; loop counting

exit:
    ret				; return the address of rax(the return register)
