#include "checker.h"

void	free_elem(t_op *instruction)
{
	if (instruction)
	{
		if (instruction->str)
			free(instruction->str);
		free(instruction);
		instruction = NULL;
	}
}

void	free_list(t_op *instructions)
{
	t_op	*current;

	current = NULL;
	while (instructions)
	{
		current = instructions;
		instructions = instructions->next;
		free_elem(current);
	}
}

void	checker_error(long *stack)
{
	if (stack)
		free(stack);
	write(2, "Error\n", 6);
	exit(-1);
}

int		checker_duplicate(int amount, long *stack, int value)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		if (stack[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int			ft_isnum(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void		checker_values(int amount, char **stack)
{
	int		i;
	long	tmp;
	long	*values;

	i = 0;
	tmp = 0;
	if (!(values = malloc(sizeof(long) * (amount + 1))))
		checker_error(NULL);
	while (i < amount)
	{
		if (stack[i] && ft_isnum(stack[i]))
		{
			tmp = ft_atol(stack[i]);
			if (checker_duplicate(i, values, tmp) == 1 ||
						tmp < INT_MIN || tmp > INT_MAX)
				checker_error(values);
			else
				values[i] = tmp;
		}
		else
			checker_error(values);
		i++;
	}
	free(values);
}

char	**checker_convert(int amount, char **args)
{
	char	**stack;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[j])
		i += ft_count_tokens(args[j++], ' ');
	stack = malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (*args)
	{
		j = 0;
		tmp = ft_split(*args, ' ');
		while (tmp[j])
			stack[i++] = ft_strdup(tmp[j++]);
		free_tab(tmp);
		args++;
	}
	stack[i] = NULL;
	return (stack);
}

void	display_stacks(int amount, char **stack_a, char **stack_b)
{
	int		i;
	int		len;
	char	tab[13];

	i = 0;
	len = 0;
	write(1, "      Stack A | Stack B\n", 25);
	while (len < 12)
			tab[len++] = ' ';
	while (i < amount)
	{
		tab[len] = '\0';
		if (stack_a[i])
		{
			write(1, tab, 13 - ft_strlen(stack_a[i]));
			ft_putstr_fd(stack_a[i], 1);
		}
		write(1, " | ", 4);
		if (stack_b[i])
			ft_putstr_fd(stack_b[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	is_sorted(char **stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (!stack[i + 1])
			break;
		if (stack[i] && ft_atol(stack[i]) < ft_atol(stack[i + 1]))
			i++;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

t_op	*get_instructions(char **stack_a, char **stack_b)
{
	char	*buffer;
	t_op	*instructions;
	t_op	*first;

	instructions = malloc(sizeof(t_op));
	first = instructions;
	while (get_next_line(0, &buffer) == 1)
	{
		instructions->str = buffer;
		instructions->next = malloc(sizeof(t_op));
		instructions = instructions->next;
		instructions->str = NULL;
		instructions->next = NULL;
	}
	free(buffer);
	return (first);
}

void	swap(char **stack)
{
	char	*tmp;

	if (stack && ft_tablen(stack) >= 2)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	align(char	**stack)
{

}

void	push(char **dst, char **src)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_tablen(src))
	{
		if (!ft_tablen(dst))
		{
			dst[i] = src[i];
			dst[i + 1] = NULL;
			while (src[i])
			{
				src[i] = src[i + 1];
				i++;
			}
			src[i] = NULL;
		}
		else
		{
			tmp = dst[0];
			dst[0] = src[0];
			while (++i < len)
			{
				tmp = dst[i + 1];
				dst[i + 1] = dst[i];
				dst[i] = tmp;
			}
			//dst = ;
		}
	}
}

void	operator(t_op *ops, char **stack_a, char **stack_b)
{
	t_op	*first;

	first = ops;
	while (ops->next)
	{
		if (!ft_strcmp(ops->str, "sa"))
			swap(stack_a);
		if (!ft_strcmp(ops->str, "sb"))
			swap(stack_b);
		if (!ft_strcmp(ops->str, "ss"))
		{
			swap(stack_a);
			swap(stack_b);
		}
		if (!ft_strcmp(ops->str, "pa"))
			push(stack_a, stack_b);
		if (!ft_strcmp(ops->str, "pb"))
			push(stack_b, stack_a);
/*		if (!ft_strcmp(ops->str, "ra"))
			rotate(stack_a, NULL);
		if (!ft_strcmp(ops->str, "rb"))
			rotate(NULL, stack_b);
		if (!ft_strcmp(ops->str, "rr"))
			rotate(stack_a, stack_b);
		if (!ft_strcmp(ops->str, "rra"))
			r_rotate(stack_a, NULL);
		if (!ft_strcmp(ops->str, "rrb"))
			r_rotate(NULL, stack_b);
		if (!ft_strcmp(ops->str, "rrr"))
			r_rotate(stack_a, stack_b);*/
		write(1, "\n----------------------\nperforming operation -> ", 48);
		write(1, ops->str, ft_strlen(ops->str));
		write(1, "\n", 1);
		ops = ops->next;
		display_stacks(ft_tablen(stack_a), stack_a, stack_b);
		is_sorted(stack_a); // ajouter verification de stack_b vide
	}
}

void	checker_core(int tokens, char **args)
{
	char	**stack_a;
	char	**stack_b;
	t_op	*ops;

	stack_a = checker_convert(tokens, args);
	checker_values(ft_tablen(stack_a), stack_a);
	stack_b = malloc(sizeof(char*) * (ft_tablen(stack_a) + 1));
	stack_b[0] = NULL;
	ops = get_instructions(stack_a, stack_b);
	operator(ops, stack_a, stack_b);
	free_tab(stack_a);
	free_tab(stack_b);
	free_list(ops);
	/*if (checker_valid(amount, stack) == -1)
		checker_error(stack);*/
}

int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		checker_core(ac, av + 1);
	}
	return (0);
}