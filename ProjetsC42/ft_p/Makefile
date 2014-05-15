#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/05/15 15:52:21 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	serveur

NAMECL = client

MAKELIB =	make -C libft/

MAKESERV =	make -C dir_serveur/

MAKECLI =	make -C dir_client/

all:		$(NAME)

$(NAME):
			$(MAKELIB) all
			$(MAKESERV) all
			$(MAKECLI) all
			mv dir_serveur/serveur .
			mv dir_client/client .
clean:
			$(MAKELIB)	clean
			$(MAKESERV)	clean
			$(MAKECLI)	clean

fclean:		clean
			$(MAKELIB)	fclean
			$(MAKESERV)	fclean
			$(MAKECLI)	fclean
			rm -rf serveur
			rm -rf client

re:			fclean all

.PHONY:		clean fclean re all
