NAME	=	push_swap

NAME_BONUS = checker

SRCS	=	src/*.c push_swap.c

SRCS_BONUS	=	src/*.c  bonus/*.c

OBJCT_BONUS	=	${SRCS_BONUS:.c=.o}

OBJCT	=	${SRCS:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(SRCS) -o $(NAME)
bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(SRCS_BONUS)
	$(CC)  $(SRCS_BONUS) -o $(NAME_BONUS)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY:		all clean fclean re bonus