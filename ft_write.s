; ft_write

	segment .text
	global	ft_write

ft_write:								; fd = rdi, buffer = rsi, bytes = rdx
			mov		rax, 0x2000004
			syscall
			ret