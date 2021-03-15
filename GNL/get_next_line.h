#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		ft_findn(char *s);
int		get_next_line(int fd, char **line);
char	*get_line(char *rem);
char	*get_remain(char *rem);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif