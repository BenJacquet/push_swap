#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* IMPLEMENTER ATOI ET ISNUM */
/* GERER "1 2 3", "1 2" "3"et "1" "2" "3" */
/* PASSER LES STACKS EN CHAR** ET ECHANGER LES POINTEURS*/

void	checker_error(int *stack)
{
	if (stack)
		free(stack);
	write(2, "Error\n", 6);
	exit(-1);
}

int		ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 1 && str[i] == '-')
	{
		if (str[])
	}
	(c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}*/

int		ft_atoi(const char *str)
{
	int					i;
	size_t				result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	uc;
	unsigned char	*dst;

	i = 0;
	uc = c;
	dst = b;
	while (len--)
		dst[i++] = uc;
	return (b);
}

int		ft_abs(int n)
{
	return (n < 0 ? -(unsigned int)n : (unsigned int)n);
}

int		ft_ilen(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
		len++;
	nb = ft_abs(n);
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nb = ft_abs(n);
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int		ft_count_tokens(const char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

/*int		checker_valid(int amount, int *stack)
{
	int		i;

	i = 0;

}*/

int		checker_duplicate(int amount, int *stack, int value)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		if (stack[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int		*checker_convert1(int *amount, char **values)
{
	int		i;
	int		j;
	int		tmp;
	int		*stack;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < *amount - 1)
		j += ft_count_tokens(values[i++], ' ');
	printf("total amount of numbers=%d\n", j);
	i = 0;
	if (!(stack = malloc(sizeof(int) * (j + 1))))
		checker_error(NULL);
	while (i < *amount - 1)
	{
		if (values[i])
		{
			while (values[i])
				tmp = ft_atoi(values[i]);
			if (checker_duplicate(i, stack, tmp) == 1)
				checker_error(stack);
			else
				stack[i] = tmp;
		}
		else
			checker_error(stack);
		i++;
	}
	return (stack);
}

/*void	display_stacks(int amount, int *stack_a, int *stack_b)
{
	int		i;
	int		len;
	char	tab[13];

	i = 0;
	len = 0;
	write(1, "      Stack A | Stack B\n", 25);
	while (len < 12)
			tab[len++] = ' ';
	while (i < amount - 1)
	{
		tab[len] = '\0';
		write(1, tab, 13 - ft_strlen(stack_a[i]));
		ft_putstr_fd(stack_a[i], 1);
		write(1, " | \n", 4);
		i++;
	}
}*/

void	checker_core(int tokens, char **values)
{
	int		*stack_a;
	int		*stack_b;

	stack_a = checker_convert1(&tokens, values);
	stack_b = malloc(sizeof(int) * (tokens + 1));
	/*if (checker_valid(amount, stack) == -1)
		checker_error(stack);*/
	//display_stacks(tokens, stack_a, stack_b);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		checker_core(ac, av + 1);
	}
	return (0);
}