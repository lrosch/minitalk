# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 14:28:43 by lrosch            #+#    #+#              #
#    Updated: 2021/11/03 13:37:13 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c ft_printers1.c ft_printers2.c ft_printers3.c \
		ft_printfhelper.c
 
NAME =	libftprintf.a

LIBFT = ./libft/libft.a

all: ${NAME}

${NAME}: ${SRC}
	$(MAKE) -C ./libft
	cp ${LIBFT} $(NAME)
	${CC} ${CC_FLAGS} -c ${SRC}
	ar r libftprintf.a *.o ft_printf.h

bonus:
	${CC} ${CC_FLAGS} -c ${BNS}
	ar r ${NAME} *.o

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
