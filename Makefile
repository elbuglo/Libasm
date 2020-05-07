# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nine <nine@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 00:28:31 by lulebugl          #+#    #+#              #
#    Updated: 2020/05/07 02:15:00 by nine             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	$(SRCS:.s=.o)

SRCS_BONUS	=	ft_list_size_bonus.s

OBJS_BONUS	=	$(SRCS_BONUS:.s=.o)

FLAGS		=	-Wall -Wextra -Werror
CC			=	clang
EXEC		=	test
EXEC_BONUS	=	test_bonus

%.o:			%.s
				nasm -felf64 $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

test:			all
					$(CC) $(FLAGS) -o $(EXEC) test.c $(NAME)

bonus:			$(OBJS) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS) $(OBJS_BONUS) 

test_bonus:			bonus
						$(CC) $(FLAGS) -o $(EXEC_BONUS) test_bonus.c $(NAME)

clean:
				rm -rf $(OBJS) $(OBJS_BONUS) 

fclean:			clean
				rm -rf $(NAME)
				rm -f $(EXEC)
				rm -f $(EXEC_BONUS)

re:				fclean $(NAME)

.PHONY:			clean fclean re test bonus test_bonus
