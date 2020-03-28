# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 00:28:31 by lulebugl          #+#    #+#              #
#    Updated: 2020/03/28 10:46:52 by lulebugl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

#SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

#OBJS		=	$(SRCS:.s=.o)

SRCS_BONUS	=	ft_list_size_bonus.s
				##ft_atoi_base_bonus.s ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s ft_list_sort_bonus.s
OBJS_BONUS	=	$(SRCS_BONUS:.s=.o)

EXEC		=	test
EXEC_BONUS	=	test_bonus
##				Ubuntu
%.o:			%.s
				nasm -f elf64 $<

##				MacOS
##%.o:			%.s
##				nasm -f macho64 $<

#all:			$(NAME)

#$(NAME):		$(OBJS)
#					ar rcs $(NAME) $(OBJS)
#test:			all
#					gcc -L. -lasm -o $(EXEC) main.c $(NAME)

bonus:			$(OBJS_BONUS)
				##$(OBJS)
				ar rcs $(NAME) $(OBJS_BONUS) 
				##$(OBJS)

test_bonus:			$(OBJS_BONUS)
					gcc -L. -lasm -o $(EXEC_BONUS) main_bonus.c $(NAME)
clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re
