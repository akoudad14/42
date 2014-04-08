#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 11:09:45 by makoudad          #+#    #+#              #
#    Updated: 2013/12/21 18:44:57 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra -pedantic

MFLAG =		-L/usr/X11/lib -lmlx -lXext -lX11

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

LIBMLX =	./usr/X11/lib

HDFLAGS =	-I$(LIBH) -I$(LIBLS) -I$(LIBMLX)

MAKELIB =	make -C libft/

NAME =		fdf

SRC =		ft_fdf.c ft_put_lines.c ft_count_wd.c ft_draw_line.c


OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(GCC) $(MFLAG) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS)

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
