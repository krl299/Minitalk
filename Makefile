LIBFT = libft/libft.a

RM = rm -rf

CFlAGS = -Wall -Werror -Wextra

GCC = gcc ${CFLAGS}

all: ${NAME}

${NAME}:
	@make -C libft/ extra
	@${GCC} server.c ${LIBFT} -o server
	@${GCC} client.c ${LIBFT} -o client

bonus: all

clean:
	${RM} libft/libft.a server client

fclean: clean

re: fclean all

.PHONY:	all	bonus	clean	fclean	re
