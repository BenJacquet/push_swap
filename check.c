#include "push_swap.h"

void	checker_error(int *stack)
{
	if (stack)
		free(stack);
	write(2, "Error\n", 6);
	exit(-1);
}

int		checker_duplicate(int amount, int *stack, int value)
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

int		is_sorted(t_stack *a, t_stack *b, int print)
{
	int		i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->values[i] < a->values[i + 1])
			i++;
		else
		{
			if (print)
			{
				printf("is not sorted ---> %d bigger than %d\n", a->values[i], a->values[i + 1]);
				write(1, "KO\n", 3);
			}
			return (1);
		}
		i++;
	}
	if (b->size)
	{
		if (print)
		{
			printf("is not sorted ---> B not empty\n");
			write(1, "KO\n", 3);
		}
		return (1);
	}
	if (print)
		write(1, "OK\n", 3);
	printf("is sorted\n");
	return (0);
}