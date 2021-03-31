#include "push_swap.h"

void	align(t_stack *stack, int mode)
{
	int		i;

	i = 0;
	if (mode == 0)
	{
		i = stack->size;
		while (i > 0)
		{
			stack->values[i] = stack->values[i - 1];
			i--;
		}
		stack->size++;
	}
	if (mode == 1)
	{
		while (i + 1 < stack->size)
		{
			stack->values[i] = stack->values[i + 1];
			i++;
		}
		stack->size--;
	}
}

void	push(t_stack *dst, t_stack *src)
{
	int		i;

	i = 0;
	if (src->size)
	{
		if (!dst->size)
		{
			dst->values[i] = src->values[i];
			dst->size++;
			align(src, 1);
		}
		else
		{
			align(dst, 0);
			dst->values[0] = src->values[0];
			align(src, 1);
		}
	}
}

void	rotate(t_stack *stack, int reverse)
{
	int		len;
	int		tmp;
	int		i;

	len = stack->size;
	i = 0;
	if (stack->size)
	{
		if (reverse)
		{
			tmp = stack->values[len - 1];
			while (len - 1 > 0)
			{
				stack->values[len - 1] = stack->values[len - 2];
				len--;
			}
			stack->values[len - 1] = tmp; 
		}
		else
		{
			tmp = stack->values[0];
			while (i + 1 < stack->size)
			{
				stack->values[i] = stack->values[i + 1];
				i++;
			}
			stack->values[stack->size - 1] = tmp; 
		}
	}
}

void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->size >= 2)
	{
		tmp = stack->values[0];
		stack->values[0] = stack->values[1];
		stack->values[1] = tmp;
	}
}

void	operator(t_op *ops, t_stack *a, t_stack *b)
{
	while (ops)
	{
		if (!ft_strcmp(ops->str, "sa"))
			swap(a);
		else if (!ft_strcmp(ops->str, "sb"))
			swap(b);
		else if (!ft_strcmp(ops->str, "ss"))
		{
			swap(a);
			swap(b);
		}
		else if (!ft_strcmp(ops->str, "pa"))
			push(a, b);
		else if (!ft_strcmp(ops->str, "pb"))
			push(b, a);
		else if (!ft_strcmp(ops->str, "ra"))
			rotate(a, 0);
		else if (!ft_strcmp(ops->str, "rb"))
			rotate(b, 0);
		else if (!ft_strcmp(ops->str, "rr"))
		{
			rotate(a, 0);
			rotate(b, 0);
		}
		else if (!ft_strcmp(ops->str, "rra"))
			rotate(a, 1);
		else if (!ft_strcmp(ops->str, "rrb"))
			rotate(b, 1);
		else if (!ft_strcmp(ops->str, "rrr"))
		{
			rotate(a, 1);
			rotate(b, 1);
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		//system("sleep 0.4");
		//system("clear");
		write(1, "----------------------\nperformed operation -> ", 47);
		write(1, ops->str, ft_strlen(ops->str));
		write(1, "\nRESULTS:\n", 10);
		int	len = (a->size >= b->size ? a->size : b->size);
		display_stacks(len, a, b);
		is_sorted(a, b, 1);
		ops = ops->next;
	}
}
/*
void	gen_ops(long *stack_a, long *stack_b)
{
	
}*/