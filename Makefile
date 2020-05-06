# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nine <nine@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 00:28:31 by lulebugl          #+#    #+#              #
#    Updated: 2020/05/07 00:25:13 by nine             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

SRCS_BONUS	=	ft_list_size_bonus.s

OBJS_BONUS	=	$(SRCS_BONUS:.s=.o)

FLAGS		=	-Wall -Werror -Wextra
CC			=	clang
EXEC		=	test
EXEC_BONUS	=	test_bonus

##				Ubuntu
%.o:			%.s
				nasm -felf64 $<

##				MacOS
##%.o:			%.s
##				nasm -f macho64 $< 
##
all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

test:			all
					$(CC) $(FLAGS) -L. -lasm -o $(EXEC) main.c $(NAME)

bonus:			$(OBJS) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS) $(OBJS_BONUS) 

test_bonus:			bonus
						$(CC) $(FLAGS) -L. -lasm -o $(EXEC_BONUS) main_bonus.c $(NAME)

clean:
				rm -rf $(OBJS) $(OBJS_BONUS) 

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re test bonus test_bonus
