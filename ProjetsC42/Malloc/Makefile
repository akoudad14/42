#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 13:06:10 by makoudad          #+#    #+#              #
#    Updated: 2014/04/19 18:35:53 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = 		gcc -Wall -Wextra -Werror -shared

NAME = 		libft_malloc_$(HOSTTYPE).so

LINK =		libft_malloc.so

SRC = 		malloc.c			\
			realloc.c			\
			free.c				\
			show_alloc_mem.c	\
			run_tiny.c			\
			run_small.c			\
			ft_print.c			\
			list_ptr.c

OBJ = 		$(SRC:.c=.o)

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

HDFLAGS =	-I$(LIBH) -I$(LIBLS)

RMF = 		rm -f

ARRC = 		ar rc

RANLIB = 	ranlib

MAKELIB = 	make -C libft/

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(ARRC) $(NAME) $(OBJ) $(LIBA)
			$(RANLIB) $(NAME)
			$(RMF) $(LINK)
			ln -s $(NAME) $(LINK)
clean:
			$(RMF) $(OBJ)

fclean:		clean
			$(RMF) $(NAME)
			$(RMF) $(LINK)

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
