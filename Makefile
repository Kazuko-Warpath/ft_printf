NAME = libftprintf.a

LIBFT = libft.a

HEADER = ft_printf.h

LIBHEADER = libft.h

LIBDIR = ./libft/

SRC = ft_printf.c ft_printf_abc.c ft_printf_dec.c ft_printf_hex.c ft_printf_ptr.c ft_printf_uns_dec.c ft_printf_utils.c

OBJ = ${SRC:.c=.o}

all: ${LIBFT} ${NAME} 

${LIBFT}: 
	make bonus -C ${LIBDIR}

${NAME}: ${OBJ} ${HEADER} ${LIBDIR}${LIBHEADER}
	ar rc ${NAME} $? ${OBJ} $? ${LIBDIR}*.o 
	

${OBJ}: ${HEADER}
	gcc -Wall -Werror -Wextra -c ${SRC}

clean:
	rm -f ${OBJ}
	make clean -C ${LIBDIR}

fclean: clean
	rm -f ${NAME}
	make fclean -C ${LIBDIR}

re: fclean all

bonus: ${OBJ} ${HEADER} ${LIBDIR}${LIBHEADER}
	ar rc ${NAME} $? ${OBJ} $? ${LIBDIR}*.o 

.phony: all clean re fclean bonus