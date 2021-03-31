#include "libft.h"

void	ft_puttab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr_fd(tab[i++], 1);
		write(1, "\n", 2);
	}
}

int		ft_tablen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		if (tab[i])
		{
			while (tab[i])
				free(tab[i++]);
		}
		free(tab);
		tab = NULL;
	}
}

char	**tab_dup(char **tab)
{
	int		i;
	char	**new;

	i = 0;
	new = NULL;
	if (tab == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(char *) * (ft_tablen(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}