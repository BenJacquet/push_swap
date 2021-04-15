/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:20 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 15:54:13 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	checker_core(char **args)
{
	t_stack	a;
	t_stack	b;
	t_op	*ops;

	parse_args(&a, args);
	b.values = malloc(sizeof(int) * (a.size));
	b.size = 0;
	ops = get_instructions();
	operator(ops, &a, &b);
	is_sorted(&a, &b, 1);
	clean_stacks(&a, &b);
	free_ops(ops);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		checker_core(av + 1);
	return (0);
}
