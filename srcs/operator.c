/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:37 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 14:32:21 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	display_stacks(int amount, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		len;
	char	tab[27];
	char	*tmp;

	i = 0;
	write(1, "      Stack A | Stack B\n", 25);
	while (i < amount)
	{
		j = 0;
		ft_memset(tab, ' ', 26);
		tab[26] = '\0';
		if (i < a->size)
		{
			len = ft_ilen(a->values[i]);
			j = 13 - len;
			tmp = ft_itoa(a->values[i]);
			ft_strcpy(tab + j, tmp);
			free(tmp);
			j += len;
		}
		else
			j = 13;
		ft_strcpy(tab + j, " | ");
		j += 3;
		if (i < b->size)
		{
			tmp = ft_itoa(b->values[i]);
			ft_strcpy(tab + j, tmp);
			free(tmp);
		}
		ft_putstr_fd(tab, 1);
		write(1, "\n", 1);
		i++;
	}
}

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
