#include "get_next_line.h"
/*
int					ft_findn(char *s)
{
	int				i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char			*get_remain(char *remain)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!remain)
		return (0);
	while (remain && remain[i] != '\0' && remain[i] != '\n')
		i++;
	if (remain[i] == '\0')
	{
		free(remain);
		return (0);
	}
	if (!(new = malloc(sizeof(char) * (ft_strlen(remain) - i) + 1)))
		return (0);
	i++;
	while (remain && remain[i] != '\0')
		new[j++] = remain[i++];
	new[j] = '\0';
	free(remain);
	return (new);
}

char			*get_line(char *remain)
{
	int			i;
	char		*new;

	i = 0;
	while (remain && remain[i] != '\0' && remain[i] != '\n')
		i++;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (remain && remain[i] != '\0' && remain[i] != '\n')
	{
		new[i] = remain[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remain;
	int			out;

	out = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (-1);
	while (!ft_findn(remain) && out != 0)
	{
		if ((out = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[out] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	*line = get_line(remain);
	printf("line=%s\n", *line);
	remain = get_remain(remain);
	if (out == 0)
		return (0);
	return (1);
}*/

char	*ft_strjoinn(char *s1, char *s2, size_t len)
{
	char			*str;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + len + 1))))
		return (NULL);
	tmp = str;
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] && len > 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str - (str - tmp));
}

int				ft_strdel(char **st)
{
	if (st != NULL)
	{
		free(*st);
		*st = NULL;
	}
	return (0);
}

static char		*new_str(char *st)
{
	if (ft_strchr(st, '\n'))
	{
		ft_strcpy(st, ft_strchr(st, '\n') + 1);
		return (st);
	}
	else if (ft_strlen(st) > 0)
	{
		ft_strcpy(st, ft_strchr(st, '\0'));
		return (st);
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	static char		*st[64];
	int				r;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(st[fd]) && !(st[fd] = ft_calloc(1, sizeof(int))))
		return (-1);
	while (!(ft_strchr(st[fd], '\n')) &&
			(r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = st[fd];
		st[fd] = ft_strjoinn(tmp, buff, r);
		free(tmp);
	}
	tmp = ft_substr(st[fd], 0, ft_strlen(st[fd]) - 1);
	*line = tmp;
	tmp = NULL;
	free(tmp);
	tmp = NULL;
	if (ft_strchr(st[fd], '\n') == NULL)
		return (ft_strdel(&st[fd]));
	return ((new_str(st[fd]) == NULL) ? 0 : 1);
}