# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 00:28:31 by lulebugl          #+#    #+#              #
#    Updated: 2020/03/28 11:15:18 by lulebugl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

SRCS_BONUS	=	ft_list_size_bonus.s

OBJS_BONUS	=	$(SRCS_BONUS:.s=.o)

FLAGS		=	-Wall -Werror -Wextra
EXEC		=	test
EXEC_BONUS	=	test_bonus

##				Ubuntu
##%.o:			%.s
##				nasm -f elf64 $<

%.o:			%.s
				nasm -f macho64 $<

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

test:			all
					gcc $(FLAGS) -L. -lasm -o $(EXEC) main.c $(NAME)
				##./$(TEST) < Makefile

bonus:			$(OBJS) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS) $(OBJS_BONUS) 

test_bonus:			bonus
						gcc $(FLAGS) -L. -lasm -o $(EXEC_BONUS) main_bonus.c $(NAME)

clean:
				rm -rf $(OBJS) $(OBJS_BONUS) 

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re test bonus test_bonus
