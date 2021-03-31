#include "push_swap.h"

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