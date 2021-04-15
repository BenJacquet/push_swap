/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:28 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:22:38 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	fill_conf(t_conf *conf, t_conf new)
{
	conf->same = new.same;
	conf->a_mov = new.a_mov;
	conf->a_moves = new.a_moves;
	conf->b_mov = new.b_mov;
	conf->b_moves = new.b_moves;
	conf->first = 0;
}

void	new_conf(t_conf *conf, t_conf tmp)
{
	if (tmp.a_mov == tmp.b_mov && tmp.a_moves == tmp.b_moves)
		tmp.same = 1;
	else if (tmp.same == 1)
	{
		if (tmp.a_moves < conf->a_moves)
			fill_conf(conf, tmp);
	}
	else if (tmp.a_moves + tmp.b_moves < conf->a_moves + conf->b_moves)
		fill_conf(conf, tmp);
}

void	adjust_moves(t_stack *a, t_stack *b, t_conf *tmp, t_pos pos)
{
	int		highest;

	highest = find_highest(a);
	if (a->values[pos.a] < b->values[pos.b])
	{
		if (pos.a > a->size / 2)
		{
			tmp->a_mov = 1;
			tmp->a_moves = (highest == pos.a ?
				a->size - highest - 1 : a->size - pos.a - 1);
		}
		else
		{
			tmp->a_mov = -1;
			tmp->a_moves = (highest == pos.a ? highest + 1 : pos.a + 1);
		}
	}
}

void	get_conf(t_stack *a, t_stack *b, t_conf *conf, t_pos pos)
{
	int		clo_p;
	t_conf	tmp;

	find_closest(a, b->values[pos.b], &clo_p);
	tmp.same = 0;
	if (pos.a == clo_p)
	{
		if (pos.a == 0)
			tmp.a_mov = 0;
		else
			tmp.a_mov = (pos.a > a->size / 2 ? 1 : -1);
		tmp.a_moves = (tmp.a_mov == 1 ? a->size - pos.a : pos.a);
		if (pos.b == 0)
			tmp.b_mov = 0;
		else
			tmp.b_mov = (pos.b > b->size / 2 ? 1 : -1);
		tmp.b_moves = (tmp.b_mov == 1 ? b->size - pos.b : pos.b);
		adjust_moves(a, b, &tmp, pos);
		if (conf->first == 1)
			fill_conf(conf, tmp);
		else
			new_conf(conf, tmp);
	}
}

void	best_rotation(t_stack *a, t_stack *b)
{
	t_pos	pos;
	t_conf	conf;

	pos.a = 0;
	conf.a_moves = -1;
	conf.b_moves = -1;
	conf.a_mov = 0;
	conf.b_mov = 0;
	conf.first = 1;
	if (!(find_highest(a) == a->size - 1 &&
		a->values[a->size - 1] < b->values[0]))
	{
		while (pos.a < a->size)
		{
			pos.b = 0;
			while (pos.b < b->size)
			{
				get_conf(a, b, &conf, pos);
				pos.b++;
			}
			pos.a++;
		}
	}
	which_rotation(a, b, conf);
}
