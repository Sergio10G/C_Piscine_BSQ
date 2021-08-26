SRCS	= ./src/file_proc.c ./src/input.c ./src/map_read.c ./src/squaretron.c ./src/helpers.c ./src/main.c ./src/matrix_funcs.c ./src/struct_funcs.c

OBJS	= ${SRCS:.c=.c}

NAME	= bsq

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
