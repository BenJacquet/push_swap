#include "push_swap.h"

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
	free(a.values);
	free(b.values);
	free_ops(ops);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		checker_core(av + 1);
	return (0);
}