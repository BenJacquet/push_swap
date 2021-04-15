NAME_1	=	checker

NAME_2	=	push_swap

SRCS_1	=	srcs/check.c\
			srcs/checker.c\
			srcs/operations.c\
			srcs/operator.c\
			srcs/parsing.c\
			srcs/utils.c\

SRCS_2	=	srcs/apply_move.c\
			srcs/check.c\
			srcs/find.c\
			srcs/generate_move.c\
			srcs/parsing.c\
			srcs/push_swap.c\
			srcs/operations.c\
			srcs/operator.c\
			srcs/sort.c\
			srcs/utils.c\

OBJS_1	=	${SRCS_1:.c=.o}

OBJS_2	=	${SRCS_2:.c=.o}

INCS	=	incs/push_swap.h

LIBFT	=	libft

LIBFTA	=	libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(LIBFTA) $(NAME_1) $(NAME_2)

srcs/%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -I $(LIBFT) -o $(^:.c=.o) -c $^

$(LIBFTA) :
	@make -C $(LIBFT) all

$(NAME_1) : $(OBJS_1)
	gcc $(CFLAGS) $^ $(GNL) $(LIBFT)/libft.a -o $(NAME_1)

$(NAME_2) : $(OBJS_2)
	gcc $(CFLAGS) $^ $(GNL) $(LIBFT)/libft.a -o $(NAME_2)

clean :
	rm -rf $(OBJS_1) $(OBJS_2)
	make -C $(LIBFT) clean

fclean : clean
	rm -rf $(NAME_1) $(NAME_2)
	make -C $(LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re