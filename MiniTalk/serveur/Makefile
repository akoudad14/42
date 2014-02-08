#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/02/08 18:55:40 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra

LIBH =		../libft/includes/

SERVH =		./

LIBA =		../libft/libft.a

HDFLAGS =	-I$(LIBH) -I$(SERVH)

NAME =		serveur

SRC =		serveur.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(GCC) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean re

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@
