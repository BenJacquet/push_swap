#include "checker.h"

/* TROUVER POURQUOI LE DISPLAY DECONNE APRES UNE OPERATION*/

void	free_op(t_op *instruction)
{
	if (instruction)
	{
		if (instruction->str)
			free(instruction->str);
		free(instruction);
		instruction = NULL;
	}
}

void	free_ops(t_op *instructions)
{
	t_op	*current;

	current = NULL;
	if (instructions)
	{
		while (instructions)
		{
			current = instructions;
			instructions = instructions->next;
			free_op(current);
		}
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;

	current = NULL;
	while (stack)
	{
		current = stack;
		stack = stack->next;
		if (current->value)
			free(current->value);
		free(current);
	}
}

int		stack_len(t_stack *stack)
{
	int		len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
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
/*
t_stack		*new_value(char *value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_stack		*checker_convert(int amount, char **args)
{
	t_stack	*stack;
	t_stack	*first;
	t_stack	*prev;
	char	**tmp;
	int		i;

	i = 0;
	while (*args)
	{
		i = 0;
		tmp = ft_split(*args, ' ');
		while (tmp[i])
		{
			stack = new_value(tmp[i]);
			if (i == 0)
			{
				first = stack;
				prev = NULL;
			}
			else
				prev = stack;
			stack = stack->next;
			stack->prev = prev;
		}
		free_tab(tmp);
		args++;
	}
	for(stack = first, i = 0; stack ; stack = stack->next)
		printf("element[%d]->  previous=[%p]  value=[%s](%p)  next=[%p]\n", i, stack->prev, stack->value, stack, stack->next);
	return (first);
}

void	display_stacks(int amount, t_stack *stack_a, t_stack *stack_b)
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
		if (stack_b && stack_b->value)
			ft_putstr_fd(stack_b->value, 1);
		write(1, "\n", 1);
		i++;
	}
}*/

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

/*void	display_stacks(int amount, char **stack_a, char **stack_b)
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
}*/

void	display_stacks(int amount, char **stack_a, char **stack_b)
{
	int		i;
	int		j;
	int		len;
	char	tab[27];

	i = 0;
	write(1, "      Stack A | Stack B\n", 25);
	while (i < amount)
	{
		j = 0;
		ft_memset(tab, ' ', 26);
		tab[26] = '\0';
		if (stack_a[i])
		{
			len = ft_strlen(stack_a[i]);
			j = 13 - len;
			ft_strcpy(tab + j, stack_a[i]);
			j += len;
		}
		ft_strcpy(tab + j, " | ");
		j += 3;
		if (i < ft_tablen(stack_b))
			ft_strcpy(tab + j, stack_b[i]);
		ft_putstr_fd(tab, 1);
		write(1, "\n", 1);
		i++;
	}
}

void	is_sorted(char **stack_a, char **stack_b)
{
	int		i;

	i = 0;
	while (stack_a[i])
	{
		if (!stack_a[i + 1])
			break;
		if (stack_a[i] && ft_atol(stack_a[i]) < ft_atol(stack_a[i + 1]))
			i++;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	if (stack_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 3);
}

t_op	*get_instructions()
{
	char	*buffer;
	t_op	*instructions;
	t_op	*first;

	instructions = malloc(sizeof(t_op));
	instructions->next = NULL;
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

void	align(char	**stack, int len, int mode)
{
	int		i;
	char	*tmp;

	i = 0;
	if (mode == 0)
	{
		/*
		ft_putstr_fd("stack[", 1);
		ft_putnbr_fd(len, 1);
		ft_putstr_fd("]=[", 1);
		ft_putstr_fd(stack[len], 1);
		ft_putstr_fd("]\n", 1);
		stack[len + 1] = NULL;
		while (len > 0)
		{
			stack[len] = stack[len - 1];
			len--;
		}
		for (int j = 0; stack[j]; j++)
			printf("stack[%d]=%s\n", j, stack[j]);*/
		//tmp = stack[0];
		i = len - 1;
		ft_putstr_fd("len=", 1);
		ft_putnbr_fd(len, 1);
		ft_putstr_fd("\n", 1);
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[len] = NULL;
	}
	if (mode == 1)
	{
		while (i < len - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
	}
	stack[i] = NULL;
}

void	push(char **dst, char **src)
{
	int		i;
	int		len;

	i = 0;
	if (ft_tablen(src))
	{
		len = ft_tablen(dst);
		if (!len)
		{
			dst[i] = src[i];
			dst[i + 1] = NULL;
			align(src, ft_tablen(src), 1);
		}
		else
		{
			align(dst, ft_tablen(dst) + 1, 0);
			dst[0] = src[0];
			align(src, ft_tablen(src), 1);
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
		else if (!ft_strcmp(ops->str, "sb"))
			swap(stack_b);
		else if (!ft_strcmp(ops->str, "ss"))
		{
			swap(stack_a);
			swap(stack_b);
		}
		else if (!ft_strcmp(ops->str, "pa"))
			push(stack_a, stack_b);
		else if (!ft_strcmp(ops->str, "pb"))
			push(stack_b, stack_a);
/*		else if (!ft_strcmp(ops->str, "ra"))
			rotate(stack_a, NULL);
		else if (!ft_strcmp(ops->str, "rb"))
			rotate(NULL, stack_b);
		else if (!ft_strcmp(ops->str, "rr"))
			rotate(stack_a, stack_b);
		else if (!ft_strcmp(ops->str, "rra"))
			r_rotate(stack_a, NULL);
		else if (!ft_strcmp(ops->str, "rrb"))
			r_rotate(NULL, stack_b);
		else if (!ft_strcmp(ops->str, "rrr"))
			r_rotate(stack_a, stack_b);*/
		write(1, "\n----------------------\nperformed operation -> ", 48);
		write(1, ops->str, ft_strlen(ops->str));
		write(1, "\nRESULTS:\n", 10);
		ops = ops->next;
		display_stacks(ft_tablen(stack_a), stack_a, stack_b);
		is_sorted(stack_a, stack_b); // ajouter verification de stack_b vide
	}
}

void	checker_core(int tokens, char **args)
{
	char	**stack_a = NULL;
	char	**stack_b = NULL;
	t_op	*ops;

	stack_a = checker_convert(tokens, args);
	checker_values(ft_tablen(stack_a), stack_a);
	stack_b = malloc(sizeof(char*) * (ft_tablen(stack_a) + 1));
	stack_b[0] = NULL;
	ops = get_instructions();
	operator(ops, stack_a, stack_b);
	//free_tab(stack_a);
	//free_tab(stack_b);
	free_ops(ops);
	/*if (checker_valid(amount, stack) == -1)
		checker_error(stack);*/
}

/*
void	operator(t_op *ops, t_stack **stack_a, t_stack **stack_b)
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
		if (!ft_strcmp(ops->str, "ra"))
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
			r_rotate(stack_a, stack_b);
		write(1, "\n----------------------\nperforming operation -> ", 48);
		write(1, ops->str, ft_strlen(ops->str));
		write(1, "\n", 1);
		ops = ops->next;
		display_stacks(ft_tablen(stack_a), stack_a, stack_b);
		is_sorted(stack_a); // ajouter verification de stack_b vide
	}
}*/

/*
void	checker_core(int tokens, char **args)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_op		*ops;

	stack_a = checker_convert(tokens, args);
	checker_values(ft_tablen(stack_a), stack_a);
	ops = get_instructions();
	//operator(ops, stack_a, stack_b);
	display_stacks(ft_tablen(stack_a), stack_a, stack_b);
	free_stack(stack_a);
	free_ops(ops);
	if (checker_valid(amount, stack) == -1)
		checker_error(stack);
}*/

int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		checker_core(ac, av + 1);
	}
	return (0);
}