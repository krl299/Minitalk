LIBFT = libft/libft.a

RM = rm -rf

CFlAGS = -Wall -Werror -Wextra

GCC = gcc ${CFLAGS}

${NAME}:	all
	
all: 
	@make -C libft extra
	@${GCC} ${CFLAGS} server.c ${LIBFT} -o server
	@${GCC} ${CFLAGS} client.c ${LIBFT} -o client

bonus: all

clean:
	@make -C libft fclean
	${RM} libft/libft.a server client

fclean: clean

re: fclean all

.PHONY:	all	bonus	clean	fclean	re
