/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:17 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 16:56:52 by jabenjam         ###   ########.fr       */
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

int		only_char(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	if (i == j)
		return (1);
	return (0);
}

void	check_null(char **args)
{
	int		i;
	int		len;

	i = 0;
	while (args[i])
	{
		len = ft_strlen(args[i]);
		if (len == 0 || only_char(args[i], ' '))
			checker_error(NULL);
		i++;
	}
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
