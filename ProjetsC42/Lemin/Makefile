#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/03/11 19:06:14 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

HDFLAGS =	-I$(LIBH) -I$(LIBLS)

MAKELIB =	make -C libft/

NAME =		lem-in

SRC =		main.c 					\
			basics.c				\
			basics2.c				\
			check_line.c			\
			save_line.c				\
			sf_check.c				\
			sf_save.c				\
			find_path.c

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
