#include "push_swap.h"

int		counter = 0;

void	find_lowest(t_stack *a, int *low, int *pos)
{
	int		i;

	i = 0;
	*low = a->values[0];
	*pos = 0;
	while (i < a->size)
	{
		if (a->values[i] < *low)
		{
			*low = a->values[i];
			*pos = i;
		}
		i++;
	}
}

void	find_highest(t_stack *a, int *high, int *pos)
{
	int		i;

	i = 0;
	*high = a->values[0];
	*pos = 0;
	while (i < a->size)
	{
		if (a->values[i] > *high)
		{
			*high = a->values[i];
			*pos = i;
		}
		i++;
	}
}

void	add_op(char *op, t_stack *a, t_stack *b)
{
	t_op	tmp;

	tmp.str = ft_strdup(op);
	tmp.next = NULL;
	operator(&tmp, a, b);
	tmp.str = ft_strjoinf(tmp.str, "\n");
	write(1, tmp.str, ft_strlen(tmp.str));
	free(tmp.str);
	counter++;
}

void	sort_last(t_stack *a, t_stack *b)
{
	int		high;
	int		pos;

	find_highest(a, &high, &pos);
	printf("hightest=%d\n", high);
	if (a->size == 2 && a->values[0] > a->values[1])
		add_op("sa", a, b);
	else if (a->size == 3)
	{
		if (pos == 0)
			add_op("ra", a, b);
		else if (pos == 2)
			add_op("sa", a, b);
		else
			add_op("rra", a, b);
		if ((a->values[0] > a->values[1] && a->values[1] > a->values[2]) ||
			(a->values[0] < a->values[1] && a->values[1] > a->values[2]))
			add_op("sa", a, b);
	}
}

t_op	*sort_stack(t_stack *a, t_stack *b)
{
	int		low;
	int		pos;

	while (1)
	{
		while (a->size > 3)
		{
			find_lowest(a, &low, &pos);
			if (pos == 0)
				add_op("pb", a, b);
			else if (pos > a->size / 2)
				add_op("rra", a, b);
			else
				add_op("ra", a, b);
		}
		if (a->size <= 3)
			sort_last(a, b);
		while (b->size)
			add_op("pa", a, b);
		if (!is_sorted(a, b, 0))
			break ;
	}
	printf("sorted using %d operations\n", counter);
}

int		push_swap(char **args)
{
	t_stack	a;
	t_stack	b;

	parse_args(&a, args);
	b.values = malloc(sizeof(int) * (a.size));
	b.size = 0;
	sort_stack(&a, &b);
	free(a.values);
	free(b.values);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(av + 1);
	return (0);
}