#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 11:09:10 by makoudad          #+#    #+#              #
#    Updated: 2014/02/08 22:00:36 by makoudad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	serveur

NAMECL = client

MAKELIB =	make -C libft/

MAKESERV =	make -C dserveur/

MAKECLI =	make -C dclient/

all:		$(NAME)

$(NAME):
			$(MAKELIB) all
			$(MAKESERV) all
			$(MAKECLI) all
			mv dserveur/serveur .
			mv dclient/client .
clean:
			$(MAKELIB)	clean
			$(MAKESERV)	clean
			$(MAKECLI)	clean

fclean:		clean
			$(MAKELIB)	fclean
			$(MAKESERV)	fclean
			$(MAKECLI)	fclean
			rm serveur
			rm client

re:			fclean all

.PHONY:		clean fclean re all
