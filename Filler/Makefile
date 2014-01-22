# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:07:00 by makoudad          #+#    #+#              #
#    Updated: 2014/01/16 11:30:58 by makoudad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			filler

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror

HDLIBFT =		./libft/includes/

HDDIR =			./includes/

HDLIB =			-I$(HDLIBFT) -I$(HDDIR)

CFILE =			filler.c			\
				ft_save.c			\
				ft_place_piece.c	\

OBJ =			$(CFILE:.c=.o)

AFILE =			./libft/libft.a

LIBMAKE =		make -C libft/

all:			$(NAME)

$(NAME):		$(OBJ)
				$(LIBMAKE)
				$(CC) $(CFLAGS) $(HDLIB) -o $(NAME) $(OBJ) $(AFILE)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

lall:
				$(LIBMAKE)

lclean:
				$(LIBMAKE) clean

lfclean:
				$(LIBMAKE) fclean

lre:
				$(LIBMAKE) re

.PHONY:			all clean fclean re lib_all lib_clean lib_fclean lib_re

%.o:			%.c
				$(CC) $(CFLAGS) $(HDLIB) -c $< -o $@
