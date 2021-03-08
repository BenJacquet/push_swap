NAME_1 = checker

NAME_2 = push_swap

SRCS =

OBJS =

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all :
	

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME_1) $(NAME_2)

re : fclean all

.PHONY : all clean fclean re