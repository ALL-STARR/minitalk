# -----------------------------------Makefile------------------------------------
NAME1	= client

NAME2	= server

# -----------------------------------Sources-------------------------------------


CLIENT_SRC	=	client.c

SERVER_SRC	=	server.c

ALL_SRC = ${CLIENT_SRC} ${SERVER_SRC}

OBJS	= ${ALL_SRC:.c=.o}

# -----------------------------------Compilation------------------------------------

FT_FOLDER = ./libft

FT = ${FT_FOLDER}/libft.a

CC		= gcc #-fsanitize=address -g

FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

MAKE_FT = make -s -C ${FT_FOLDER}

# -----------------------------------Libraries--------------------------------------

INCLUDES = -I ./includes

# -----------------------------------Rules------------------------------------------

all: server client

server : ${FT} server.o 
		${CC} ${FLAGS} -o ${NAME2} ${SERVER_SRC} ${FT}

client : ${FT} client.o
		${CC} ${FLAGS} -o ${NAME1} ${CLIENT_SRC} ${FT}

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${FT}: 
		${MAKE_FT}

re: fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME2} ${NAME1}
		${MAKE_FT} fclean

# -----------------------------------.phony--------------------------------------

.PHONY: all clean fclean re