#include "push_swap.h"
/*
t_op	*get_instructions()
{
	char	*buffer;
	int		ret;
	t_op	*instructions;
	t_op	*first;
	int	i;

	first = NULL;
	while (1)
	{
		ret = get_next_line(0, &buffer);
		printf("ret=%d|buffer=%s\n", ret, buffer);
		if (!ret)
		{
			free(buffer);
			break ;
		}
		else
		{
			if (!first)
				first = instructions;
			instructions = malloc(sizeof(t_op));
			instructions->str = buffer;
			instructions->next = NULL;
		}
		for (i = 0; instructions; instructions = instructions->next)
			i++;
		printf("found %d operations to perform\n", i);
		instructions = instructions->next;
	}
	instructions = first;
	for (i = 0; instructions; instructions = instructions->next)
		i++;
	printf("found %d operations to perform\n", i);
	return (first);
}*/

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
			free(current->str);
			free(current);
		}
	}
}

t_op		*new_op(char *str)
{
	t_op	*new;

	new = NULL;
	if (str)
	{
		if (!(new = malloc(sizeof(t_op))))
			return (NULL);
		new->str = str;
		new->next = NULL;
	}
	return (new);
}

t_op		*split_instructions(char **split)
{
	t_op	*ops;
	t_op	*first;
	int		i;

	i = 0;
	first = NULL;
	ops = NULL;
	if (split)
	{
		if (split[i])
			ops = new_op(split[i++]);
		first = ops;
		while (split[i])
		{
			ops->next = new_op(split[i++]);
			ops = ops->next;
		}
	}
	free(split);
	return (first);
}

t_op		*get_instructions()
{
	char	buffer[4097];
	char	*joined;
	char	**split;
	int		bytes;

	joined = ft_strdup("\0");
	bytes = 1;
	while (1)
	{
		bytes = read(0, buffer, 4096);
		if (!bytes)
			break ;
		buffer[bytes] = '\0';
		joined = ft_strjoinf(joined, buffer);
	}
	split = ft_split(joined, '\n');
	free(joined);
	return (split_instructions(split));
}

void		get_stack(t_stack *a, int amount, char **stack)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	if (!(a->values = malloc(sizeof(long) * (amount + 1))))
		checker_error(NULL);
	a->size = amount;
	while (i < amount)
	{
		if (stack[i] && ft_isnum(stack[i]))
		{
			tmp = ft_atol(stack[i]);
			if (checker_duplicate(i, a->values, tmp) == 1 ||
						tmp < INT_MIN || tmp > INT_MAX)
				checker_error(a->values);
			else
				a->values[i] = (int)tmp;
		}
		else
			checker_error(a->values);
		i++;
	}
	free_tab(stack);
}

void		parse_args(t_stack *a, char **args)
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
	get_stack(a, i, stack);
}