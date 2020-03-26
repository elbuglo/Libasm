# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 00:28:31 by lulebugl          #+#    #+#              #
#    Updated: 2020/03/26 04:15:36 by lulebugl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s
##ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)

EXEC		=	test
%.o:			%.s
				nasm -f elf64 $<

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)
test:			all
					gcc -L. -lasm -o $(EXEC) main.c $(NAME)
clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re