NAME_1	=	checker

NAME_2	=	push_swap

SRCS_1	=	check.c\
			checker.c\
			display.c\
			operations.c\
			parsing.c\
			utils.c\

GNL		=	GNL/get_next_line.c

SRCS_2	=	check.c\
			display.c\
			parsing.c\
			push_swap.c\
			operations.c\
			utils.c\

OBJS_1	=	${SRCS_1:.c=.o}

OBJS_2	=	${SRCS_2:.c=.o}

INCS	=	push_swap.h

LIBFT	=	libft

LIBFTA	=	libft.a

CC = gcc

CFLAGS = -fsanitize=address #-Wall -Werror -Wextra

all : $(LIBFTA) $(NAME_1) $(NAME_2)

.c.o: $(SRCS_1) $(SRCS_1)
	$(CC) $(CFLAGS) $(INCS) -I $(LIBFT) -c $^

$(LIBFTA) :
	@make -C $(LIBFT) all


$(NAME_1) : $(OBJS_1)
	gcc $(CFLAGS) $(OBJS_1) $(GNL) $(LIBFT)/libft.a -o $(NAME_1)

$(NAME_2) : $(OBJS_2) 
	gcc $(CFLAGS) $(OBJS_2) $(GNL) $(LIBFT)/libft.a -o $(NAME_2)

clean :
	rm -rf $(OBJS_1) $(OBJS_2)
	make -C $(LIBFT) clean

fclean : clean
	rm -rf $(NAME_1) $(NAME_2)
	make -C $(LIBFT) fclean

re : fclean all

.PHONY : all clean fclean re