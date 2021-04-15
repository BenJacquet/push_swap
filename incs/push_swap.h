/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:56:56 by jabenjam          #+#    #+#             */
/*   Updated: 2021/04/15 16:45:41 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

/*
** -------------------------------------------------------------------------
** STRUCTURES
** -------------------------------------------------------------------------
*/

typedef	struct	s_op
{
	char		*str;
	void		*next;
}				t_op;

typedef	struct	s_stack
{
	int			*values;
	int			size;
}				t_stack;

typedef struct	s_conf
{
	int			a_mov;
	int			a_moves;
	int			b_mov;
	int			b_moves;
	int			same;
	int			first;
}				t_conf;

typedef struct	s_pos
{
	int			a;
	int			b;
}				t_pos;

/*
** -------------------------------------------------------------------------
** CHECKER
** -------------------------------------------------------------------------
*/

void			checker_core(char **args);
int				is_sorted(t_stack *a, t_stack *b, int print);
int				checker_duplicate(int amount, int *stack, int value);
void			checker_error(int *stack);

/*
** -------------------------------------------------------------------------
** SORT
** -------------------------------------------------------------------------
*/

int				push_swap(char **args);
void			which_rotation(t_stack *a, t_stack *b, t_conf conf);
void			different_rotation(t_stack *a, t_stack *b, t_conf conf);
void			same_rotation(t_stack *a, t_stack *b, t_conf conf);
void			add_op(char *op, t_stack *a, t_stack *b);
void			best_rotation(t_stack *a, t_stack *b);
void			get_conf(t_stack *a, t_stack *b, t_conf	*conf, t_pos pos);
void			adjust_moves(t_stack *a, t_stack *b, t_conf *tmp, t_pos pos);
void			new_conf(t_conf *conf, t_conf tmp);
void			fill_conf(t_conf *conf, t_conf new);
void			sort_stack(t_stack *a, t_stack *b);
void			sort_small(t_stack *a, t_stack *b);
void			sort_last(t_stack *a, t_stack *b);

/*
** -------------------------------------------------------------------------
** PARSING
** -------------------------------------------------------------------------
*/

t_op			*new_op(char *str);
t_op			*split_instructions(char **split);
t_op			*get_instructions();
void			get_stack(t_stack *a, int amount, char **stack);
void			parse_args(t_stack *a, char **args);
int				ft_isnum(char *str);
void			check_null(char **args);
int				only_char(char *str, char c);

/*
** -------------------------------------------------------------------------
** CLEAR
** -------------------------------------------------------------------------
*/

void			free_ops(t_op *instructions);
void			clean_stacks(t_stack *a, t_stack *b);

/*
** -------------------------------------------------------------------------
** FIND VALUES
** -------------------------------------------------------------------------
*/

void			find_lowest(t_stack *a, int *low, int *pos);
int				find_highest(t_stack *a);
int				find_closest(t_stack *stack, int target, int *pos);
int				smaller(int a, int b);

/*
** -------------------------------------------------------------------------
** MOVES
** -------------------------------------------------------------------------
*/

void			swap(t_stack *stack);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			push(t_stack *dst, t_stack *src);
void			align(t_stack *stack, int mode);
void			operator(t_op *ops, t_stack *a, t_stack *b);
int				operator_2(t_op *ops, t_stack *a, t_stack *b);
int				operator_3(t_op *ops, t_stack *a, t_stack *b);

#endif
