NAME		= rush-02

SRCS		= main.c ft_io.c ft_string.c ft_memory.c ft_atoi.c ft_dict.c ft_parse_dict.c ft_read_dict.c ft_dict_match.c ft_display.c ft_dict2.c ft_test.c ft_words.c ft_match.c ft_dict_add_scale.c ft_dict_add_value.c ft_dict_ctype.c ft_parse_dict_help.c ft_echo.c

OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror

${ODIR}/%.o:
	gcc ${CFLAGS} -c ${@:.o=.c} -o $@

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

${NAME}: ${OBJS}
	gcc ${CFLAGS} ${OBJS} -o ${NAME}
