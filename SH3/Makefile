#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/02/07 12:00:00 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC =		gcc -Wall -Werror -Wextra -pedantic -g

LIBH =		./libft/includes/

LIBA =		./libft/libft.a

LIBLS =		./includes/

HDFLAGS =	-I$(LIBH) -I$(LIBLS)

MAKELIB =	make -C libft/

NAME =		ft_minishell3

SRC =		main.c							\
			change_terminal_mode.c			\
			save_line.c						\
			is_key_arrow.c					\
			is_key_change_line.c			\
			is_key_copy.c					\
			is_key_cut_paste.c				\
			is_key_del_or_enter.c			\
			is_key_fast_move.c				\
			ft_len.c						\
			ft_list_put_elem.c				\
			fast_cursor_move.c				\
			ft_change_line.c				\
			ft_historic.c					\
			ft_list_del.c					\
			ft_print.c						\
			ft_cut_copy_or_paste.c			\
			do_line.c						\
			ft_special.c					\
			ft_direct.c						\
			ft_env.c						\
			ft_exe.c						\
			ft_check_env_and_signal.c		\
			ft_right.c						\
			ft_left.c						\
			ft_pipe.c						\
			ft_check_exe.c					\
			ft_builtin.c					\
			ft_exit.c


OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(GCC) -o $(NAME) $(OBJ) $(LIBA) $(HDFLAGS) -ltermcap

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
