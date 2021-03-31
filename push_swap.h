#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

typedef	struct	s_op
{
	char		*str;
	void		*next;
}				t_op;

typedef	struct	s_stack
{
	int			*values;
	int			size;
}				t_stack;


void		checker_core(char **args);
void		display_stacks(int amount, t_stack *a, t_stack *b);
void		free_ops(t_op *instructions);
void		parse_args(t_stack *a, char **args);
void		get_stack(t_stack *a, int amount, char **stack);
int			is_sorted(t_stack *a, t_stack *b, int print);
int			checker_duplicate(int amount, int *stack, int value);
void		checker_error(int *stack);
int			ft_isnum(char *str);
void		swap(t_stack *stack);
void		operator(t_op *ops, t_stack *a, t_stack *b);
void		rotate(t_stack *stack, int reverse);
void		push(t_stack *dst, t_stack *src);
void		align(t_stack *stack, int mode);
t_op		*get_instructions();

# endif