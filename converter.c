#include <stdio.h>
#include "libft/libft.h"

int		main(int ac, char **av)
{
	char	**stack;
	char	**tmp;
	int	i = 1;
	int	j = 0;
	int	k = 0;

	while (i < ac)
		j += ft_count_tokens(av[i++], ' ');
	stack = malloc(sizeof(char*) * (j + 1));
	i = 1;
	j = 0;
	while (i < ac && av[i])
	{
		k = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[k])
			stack[j++] = ft_strdup(tmp[k++]);
		free_tab(tmp);
		i++;
	}
	stack[j] = NULL;
	printf("found %d numbers :\n", j);
	j = 0;
	while (stack[j])
		printf("%s\n", stack[j++]);
	free_tab(stack);
}