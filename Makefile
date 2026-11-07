NAME = push_swap
SLIB = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c checking_args_util.c extra_func.c modified_libft_util.c operations.c operations2.c sort_simple.c\
sort_complex.c sort_medium.c sort_utils.c
OBJS = ${SRCS:.c=.o}
VAR = ar rcs
HEADER = push_swap.h
BOUNS_SRCS = operations_bouns.c operations2_bouns.c
BOUNS_OBJS = ${BOUNS_SRCS:.c=.o}
all : ${NAME}
${NAME} : ${SLIB}
		${CC} ${CFLAGS} main.c ${SLIB} -o ${NAME}
${SLIB} : SUBMAKE ${OBJS} ${HEADER}
	cp libft/libft.a ${SLIB}
	${VAR} ${SLIB} ${OBJS}
SUBMAKE : 
	make -C libft
bouns : ${SLIB}
	${CC} ${CFLAGS} main_bouns.c ${BOUNS_SRCS} ${SLIB} -o checker
clean :
	make clean -C libft
	rm -f ${OBJS} ${BOUNS_OBJS}
fclean : clean
	make fclean -C libft
	rm -f ${SLIB} ${NAME} checker
re : fclean all
.PHONY: all clean fclean re SUBMAKE
