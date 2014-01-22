#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:06:10 by makoudad          #+#    #+#              #
#    Updated: 2013/12/19 21:02:07 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = 		gcc -Wall -Werror -Wextra -pedantic

NAME = 		libftprintf.a

SRC = 		ft_printf.c				\
			ft_printf_arg.c			\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putnbr.c				\
			ft_strdup.c				\
			ft_strlen.c				\
			ft_strcpy.c				\
			ft_strcat.c				\
			ft_strnew.c				\
			ft_putendl.c			\
			ft_strjoin.c			\
			ft_format.c				\
			ft_arg.c				\
			ft_itoa.c				\
			ft_toa.c				\
			ft_stoa.c				\
			ft_ltoa.c

OBJ = 		$(SRC:.c=.o)

HDDIR = 	./includes/

HDFLAGS = 	-I$(HDDIR)

RMF = 		rm -f

ARRC = 		ar rc

RANLIB = 	ranlib

all:		$(NAME)

$(NAME):	$(OBJ)
			$(ARRC) $(NAME) $(OBJ)
			$(RANLIB) $(NAME)

clean:
			$(RMF) $(OBJ)

fclean:		clean
			$(RMF) $(NAME)

re:			fclean all

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@

.PHONY:		clean re fclean
