# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 12:56:19 by lrosch            #+#    #+#              #
#    Updated: 2021/11/09 14:52:58 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

FLAGS =	-Wall -Wextra -Werror

NAME = minitalk.a

SERVER = server

SERVER_O = server.c

CLIENT = client

CLIENT_O = client.c

LIBFT = ./libft+/libftplus.a

all: $(NAME)


${NAME}: ${CLIENT} ${SERVER}
	$(MAKE) -C ./libft+
	cp libft+/libftplus.a $(NAME)
	$(CC) $(FLAGS) -c $(SERVER_O) ${CLIENT_O}
	ar rc $(NAME) *.o

client: libft 
	${CC} ${FLAGS} ${CLIENT_O} ${LIBFT} -o ${CLIENT}

server: libft
	${CC} ${FLAGS} ${SERVER_O} ${LIBFT} -o ${SERVER}

libft:
	$(MAKE) -C ./libft+

clean:
	rm -f *.o
	${MAKE} -C ./libft+ clean

fclean: clean
	rm -f a.out
	rm -f minitalk.a
	rm -f server
	rm -f client
	${MAKE} -C ./libft+ fclean

re: fclean
	${MAKE} -C ./libft+ fclean
	${MAKE} all