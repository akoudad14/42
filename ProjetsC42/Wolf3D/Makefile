# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 16:07:00 by makoudad          #+#    #+#              #
#    Updated: 2014/01/13 10:40:38 by makoudad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			wolf3d

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror

MINIFLAGS =		-L/usr/X11/lib -lmlx -lXext -lX11

HDLIBFT =		./libft/includes/

HDDIR =			./includes/

HDLIB =			-I$(HDLIBFT) -I$(HDDIR)

CFILE =			main.c					\
				ft_draw.c				\
				ft_draw_line.c			\
				ft_parse_map.c

OBJ =			$(CFILE:.c=.o)

AFILE =			./libft/libft.a

LIBMAKE =		make -C libft/

all:			$(NAME)

$(NAME):		$(OBJ)
				$(LIBMAKE)
				$(CC) $(MINIFLAGS) $(CFLAGS) $(HDLIB) -o $(NAME) $(OBJ) $(AFILE)

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
