#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/01/05 15:17:56 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -O3 -Wall -Werror -Wextra -pedantic

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

HDFLAGS =	-I$(LIBH) -I$(LIBLS)

MAKELIB =	make -C libft/

NAME =		pipex

SRC =		ft_pipex.c ft_check.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(GCC) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

lall:
			$(MAKELIB)

lclean:
			$(MAKELIB) clean

lfclean:
			$(MAKELIB) fclean

lre:		lfclean lall

.PHONY:		clean fclean re all lall lclean lfclean lre

%.o:		%.c
			$(GCC) $(HDFLAGS) -c $< -o $@
