#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"

typedef	struct	s_op
{
	char		*str;
	void		*next;
}				t_op;

typedef struct s_stack
{
	char		*value;
	void		*preview;
	void		*next;
}				t_stack;


# endif