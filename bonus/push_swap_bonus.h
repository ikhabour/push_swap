/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:37:32 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/07 23:59:09 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line_bonus.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct st
{
	int			data;
	struct st	*next;
}				t_struct;

typedef struct st3
{
	int			i;
	int			j;
	char		**tmp;
}				t_main;

//             Functions                //

int				ft_atoi(const char *str);
int				ft_isdigit(char *str);
int				stack_a_is_sorted(t_struct **a);
void			swap(int *a, int *b);
void			check_arguments(char **split_arg);
char			**ft_split(const char *s, char c);
t_struct		*make_stack(int argc, char **argv);
void			check_duplicates(t_struct **stack);
t_struct		*ft_lstnew(int data);
int				ft_lstsize(t_struct *lst);
t_struct		*ft_lstlast(t_struct *lst);
void			ft_lstadd_front(t_struct **lst, t_struct *new);
void			ft_lstadd_back(t_struct **lst, t_struct *new);
void			do_instructions(char *instruction, t_struct **a, t_struct **b);
void			do_instructions(char *instruction, t_struct **a, t_struct **b);
void			ft_free_tmp(char **tmp);
int				ft_strcmp(char *s1, char *s2);
void			printerror(void);

//             Instructions             //

void			sa(t_struct **a, t_struct **b);
void			sb(t_struct **a, t_struct **b);
void			ss(t_struct **a, t_struct **b);
void			pa(t_struct **a, t_struct **b);
void			pb(t_struct **a, t_struct **b);
void			ra(t_struct **a, t_struct **b);
void			rb(t_struct **a, t_struct **b);
void			rr(t_struct **a, t_struct **b);
void			rra(t_struct **a, t_struct **b);
void			rrb(t_struct **a, t_struct **b);
void			rrr(t_struct **a, t_struct **b);

#endif