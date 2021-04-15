/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:47 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:20:38 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sort_last(t_stack *a, t_stack *b)
{
	int		pos;

	pos = find_highest(a);
	if (a->size == 2)
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
			(a->values[0] < a->values[1] && a->values[1] > a->values[2]) ||
			(a->values[0] > a->values[1] && a->values[1] < a->values[2]))
			add_op("sa", a, b);
	}
}

void	sort_small(t_stack *a, t_stack *b)
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
}

void	sort_stack(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		add_op("pb", a, b);
	sort_last(a, b);
	while (b->size)
		best_rotation(a, b);
	while (is_sorted(a, b, 0))
		add_op("ra", a, b);
}
