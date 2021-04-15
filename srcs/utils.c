/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:52 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:23:07 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		ft_isnum(char *str)
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

void	clean_stacks(t_stack *a, t_stack *b)
{
	free(a->values);
	free(b->values);
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
			free(current->str);
			free(current);
		}
	}
}
