/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:34 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 13:56:34 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	align(t_stack *stack, int mode)
{
	int		i;

	i = 0;
	if (mode == 0)
	{
		i = stack->size;
		while (i > 0)
		{
			stack->values[i] = stack->values[i - 1];
			i--;
		}
		stack->size++;
	}
	if (mode == 1)
	{
		while (i + 1 < stack->size)
		{
			stack->values[i] = stack->values[i + 1];
			i++;
		}
		stack->size--;
	}
}

void	push(t_stack *dst, t_stack *src)
{
	int		i;

	i = 0;
	if (src->size)
	{
		if (!dst->size)
		{
			dst->values[i] = src->values[i];
			dst->size++;
			align(src, 1);
		}
		else
		{
			align(dst, 0);
			dst->values[0] = src->values[0];
			align(src, 1);
		}
	}
}
/*
void	rotate(t_stack *stack, int reverse)
{
	int		len;
	int		tmp;
	int		i;

	len = stack->size;
	i = 0;
	if (stack->size)
	{
		if (reverse)
		{
			tmp = stack->values[len - 1];
			while (len - 1 > 0)
			{
				stack->values[len - 1] = stack->values[len - 2];
				len--;
			}
			stack->values[len - 1] = tmp; 
		}
		else
		{
			tmp = stack->values[0];
			while (i + 1 < stack->size)
			{
				stack->values[i] = stack->values[i + 1];
				i++;
			}
			stack->values[stack->size - 1] = tmp; 
		}
	}
}*/

void	rotate(t_stack *stack, int reverse)
{
	int		len;
	int		tmp;
	int		i;

	len = stack->size + 1;
	i = -1;
	if (stack->size)
	{
		if (reverse)
		{
			tmp = stack->values[len - 1];
			while (--len - 1 > 0)
				stack->values[len - 1] = stack->values[len - 2];
			stack->values[len - 1] = tmp; 
		}
		else
		{
			tmp = stack->values[0];
			while (++i + 1 < stack->size)
				stack->values[i] = stack->values[i + 1];
			stack->values[stack->size - 1] = tmp; 
		}
	}
}

void	swap(t_stack *stack)
{
	int		tmp;

	if (stack->size >= 2)
	{
		tmp = stack->values[0];
		stack->values[0] = stack->values[1];
		stack->values[1] = tmp;
	}
}
