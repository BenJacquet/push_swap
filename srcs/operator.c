/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:37 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 13:56:37 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		operator_3(t_op *ops, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(ops->str, "ra"))
		rotate(a, 0);
	else if (!ft_strcmp(ops->str, "rb"))
		rotate(b, 0);
	else if (!ft_strcmp(ops->str, "rr"))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!ft_strcmp(ops->str, "rra"))
		rotate(a, 1);
	else if (!ft_strcmp(ops->str, "rrb"))
		rotate(b, 1);
	else if (!ft_strcmp(ops->str, "rrr"))
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	else
		return (0);
	return (1);
}

int		operator_2(t_op *ops, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(ops->str, "sa"))
		swap(a);
	else if (!ft_strcmp(ops->str, "sb"))
		swap(b);
	else if (!ft_strcmp(ops->str, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(ops->str, "pa"))
		push(a, b);
	else if (!ft_strcmp(ops->str, "pb"))
		push(b, a);
	else
		return (0);
	return (1);
}

void	operator(t_op *ops, t_stack *a, t_stack *b)
{
	while (ops)
	{
		if (operator_2(ops, a, b))
			ops = ops->next;
		else if (operator_3(ops, a, b))
			ops = ops->next;
		else
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
	}
}
