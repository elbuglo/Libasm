;ft_strlen.s
segment .text
    global ft_strlen

ft_strlen:
    mov     rax, 0
    jmp     count	; start counting

count:
    cmp     BYTE [rdi + rax], 0
    je      exit
    inc     rax		; increment the value of rax by one
    jmp     count 	; loop counting

exit:
    ret
