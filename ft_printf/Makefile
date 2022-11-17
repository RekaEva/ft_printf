# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:14:09 by cpollito          #+#    #+#              #
#    Updated: 2022/01/07 17:17:04 by cpollito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf.c

HEADER 	= ft_printf.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra 
RM 		= rm -f

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) 

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all