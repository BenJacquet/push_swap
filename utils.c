#include "push_swap.h"

int			ft_isnum(char *str)
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