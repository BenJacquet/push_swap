/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:11 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 14:11:37 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	add_op(char *op, t_stack *a, t_stack *b)
{
	t_op	tmp;

	tmp.str = ft_strdup(op);
	tmp.next = NULL;
	operator(&tmp, a, b);
	tmp.str = ft_strjoinf(tmp.str, "\n");
	write(1, tmp.str, ft_strlen(tmp.str));
	free(tmp.str);
}

void	same_rotation(t_stack *a, t_stack *b, t_conf conf)
{
	while (conf.a_moves > 0)
	{
		if (conf.a_mov == -1)
			add_op("rr", a, b);
		else
			add_op("rrr", a, b);
		conf.a_moves--;
	}
}

void	different_rotation(t_stack *a, t_stack *b, t_conf conf)
{
	while (conf.a_moves > 0)
	{
		if (conf.a_mov == -1)
			add_op("ra", a, b);
		else
			add_op("rra", a, b);
		conf.a_moves--;
	}
	while (conf.b_moves > 0)
	{
		if (conf.b_mov == -1)
			add_op("rb", a, b);
		else
			add_op("rrb", a, b);
		conf.b_moves--;
	}
}

void	which_rotation(t_stack *a, t_stack *b, t_conf conf)
{
	if ((conf.a_mov || conf.b_mov) && !conf.first)
	{
		if (conf.same == 1)
			same_rotation(a, b, conf);
		else
			different_rotation(a, b, conf);
	}
	add_op("pa", a, b);
}