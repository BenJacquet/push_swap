/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:25 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:20:21 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

int		find_highest(t_stack *a)
{
	int		i;
	int		pos;
	int		high;

	i = 0;
	high = a->values[0];
	pos = 0;
	while (i < a->size)
	{
		if (a->values[i] > high)
		{
			high = a->values[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		find_closest(t_stack *stack, int target, int *pos)
{
	int		closest;
	int		i;

	closest = stack->values[0];
	*pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (ft_abs(stack->values[i] - target) < ft_abs(closest - target))
		{
			closest = stack->values[i];
			*pos = i;
		}
		i++;
	}
	if (closest < target)
		return (0);
	return (1);
}

int		smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
