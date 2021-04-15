/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:37 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 17:09:48 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		operator_3(t_op *ops, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(ops->str, "ra"))
		rotate(a);
	else if (!ft_strcmp(ops->str, "rb"))
		rotate(b);
	else if (!ft_strcmp(ops->str, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(ops->str, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(ops->str, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(ops->str, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
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

int		operator(t_op *ops, t_stack *a, t_stack *b)
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
			return (1);
		}
	}
	return (0);
}
