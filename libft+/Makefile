# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 12:54:46 by lrosch            #+#    #+#              #
#    Updated: 2021/10/29 14:45:31 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
NAME =		libftplus.a
CFLAGS	=	-Wall -Werror -Wextra

${NAME}:
	${MAKE} -C ./libft
	ar rc ${NAME} libft/*.o
	${MAKE} -C ./ft_printf 
	ar rc ${NAME} ft_printf/*.o

all: $(NAME)
	
bonus: all

clean:
	${MAKE} -C ./libft clean
	${MAKE} -C ./ft_printf  clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ./libft fclean
	${MAKE} -C ./ft_printf fclean

re: fclean all
	${MAKE} -C ./libft fclean
	${MAKE} -C ./ft_printf  fclean