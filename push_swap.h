/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:36:43 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 00:01:23 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct st1
{
	int			mid;
	int			start;
	int			end;
	int			offset;
}				t_chunk;

typedef struct st2
{
	int			*array;
	int			size;
	int			index;
}				t_array;

typedef struct st3
{
	int			i;
	int			j;
	char		**tmp;
}				t_main;

char			**ft_split(const char *s, char c);
int				ft_atoi(const char *str);
void			ft_lstadd_back(t_struct **lst, t_struct *new);
void			ft_lstadd_front(t_struct **lst, t_struct *new);
t_struct		*ft_lstnew(int data);
t_struct		*ft_lstlast(t_struct *lst);
void			printerror(void);
int				ft_isdigit(char *str);
int				ft_lstsize(t_struct *lst);
void			swap(int *a, int *b);
void			quick_sort(int *array, int length);
void			quick_sort_recursion(int *array, int low, int high);
int				partition(int *array, int low, int high);
void			check_arguments(char **split_arg);
int				stack_a_is_sorted(t_struct **a);
void			sort_three_numbers(t_struct **a, t_struct **b);
int				find_min_value(t_struct **a, int *count);
void			ft_free_tmp(char **tmp);
void			check_duplicates(t_struct **stack);
t_struct		*make_stack(int argc, char **argv);
int				*store_stack_in_array(t_struct **a);
int				function(t_struct **a, int max);
int				find_max_index(t_struct **b, int max);
void			from_b_to_a(t_struct **a, t_struct **b, t_array *ar);
int				check_numbers(t_struct **a, t_chunk *c, t_array *ar,
					int *index);
void			from_a_to_b(t_struct **a, t_struct **b, t_array *ar,
					t_chunk *c);
void			ft_range(t_chunk *c, t_array *ar);
void			check_list_size(t_chunk *c, t_array *ar);
void			rb_or_rrb(t_struct **a, t_struct **b, t_array *ar, int count);
void			bottom(t_struct **a, t_struct **b, int *a_bottom);
void			bottom2(t_struct **a, t_struct **b, int *a_bottom, t_array *ar);
void			bottom3(t_struct **a, t_struct **b, int *a_bottom);
void			validate_arguments(t_main var, int argc, char **argv);
int				ft_strcmp(char *s1, char *s2);
void			sort_two_numbers(t_struct **a, t_struct **b);

//              Instructions                //

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