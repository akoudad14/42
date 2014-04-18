#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:06:10 by makoudad          #+#    #+#              #
#    Updated: 2014/04/18 17:24:35 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = 		gcc -Wall -Wextra -Werror -pedantic -ansi

NAME = 		libft.a

SRC = 		ft_memset.c			\
			ft_memcpy.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putstr.c			\
			ft_toh.c			\
			ft_putchar.c		\
			ft_put_base.c		\
			ft_strlen.c

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

.PHONY:		all clean re fclean
