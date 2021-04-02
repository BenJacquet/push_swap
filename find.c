#include "push_swap.h"

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

void	find_median(t_stack *a, int *closest, int *pos)
{
	long long int	total;
	int				median;
	int				diff;
	int				i;

	*closest = 0;
	*pos = 0;
	median = 0;
	total = 0;
	i = 0;
	while (i < a->size)
	{
		total = (total == 0 ? a->values[i] : total + a->values[i]);
		i++;
	}
	median = total / a->size;
	i = 0;
	while (i < a->size)
	{
		///printf("test %d\n", a->values[i]);
		if (ft_abs(a->values[i] - median) < ft_abs(*closest - median))
		{
			*closest = a->values[i];
			*pos = i;
		}
		i++;
	}
	//printf("median = %d closest=%d\n", median, *closest);
}