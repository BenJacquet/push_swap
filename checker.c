#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* IMPLEMENTER ATOI ET ISNUM */
/* GERER "1 2 3", "1 2" "3"et "1" "2" "3" */

void	checker_error(int *stack)
{
	if (stack)
		free(stack);
	write(2, "Error\n", 8);
	exit(-1);
}

int		checker_valid(int amount, int *stack)
{
	int		i;

	i = 0;

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

int		*checker_convert(int amount, char **values)
{
	int		i;
	int		tmp;
	int		*stack;

	i = 0;
	tmp = 0;
	if (!(stack = malloc(sizeof(int) * (amount + 1))))
		checker_error(NULL);
	while (i < amount)
	{
		if (values[i] && ft_isnum(values[i]))
		{
			tmp = ft_atoi(values[i]);
			if (checker_duplicate(i, stack, tmp) == 1)
				checker_error(stack);
			else
				stack[i] = tmp;
		}
		else
			checker_error(stack);
		i++;
	}
	return (stack);
}

void	checker_core(int amount, char **values)
{
	int		*stack;

	stack = checker_convert(amount, values);
	if (checker_valid(amount, stack) == -1)
		checker_error(stack);
}


int		main(int ac, char **av)
{
	if (ac != 2)
	{
		checker_core(ac, av);
	}
	return (0);
}