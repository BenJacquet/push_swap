/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:17 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:55:36 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
				write(1, "KO\n", 3);
			return (1);
		}
	}
	if (b->size)
	{
		if (print)
			write(1, "KO\n", 3);
		return (1);
	}
	if (print)
		write(1, "OK\n", 3);
	return (0);
}
