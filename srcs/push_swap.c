/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:23:17 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 17:10:29 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		push_swap(char **args)
{
	t_stack	a;
	t_stack	b;

	check_null(args);
	parse_args(&a, args);
	b.values = malloc(sizeof(int) * (a.size));
	b.size = 0;
	if (is_sorted(&a, &b, 0))
	{
		if (a.size <= 3)
			sort_last(&a, &b);
		else if (a.size <= 10)
			sort_small(&a, &b);
		else
			sort_stack(&a, &b);
	}
	clean_stacks(&a, &b);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(av + 1);
	return (0);
}
