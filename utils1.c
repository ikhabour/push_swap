/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:15:56 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 01:10:01 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(char **split_arg)
{
	int	i;

	i = 0;
	while (split_arg[i])
	{
		if (ft_isdigit(split_arg[i]) == 0)
			printerror();
		i++;
	}
	if (i == 0)
		printerror();
}

int	stack_a_is_sorted(t_struct **a)
{
	t_struct	*tmp;

	tmp = *a;
	while (tmp && tmp->next && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	return (1);
}

void	sort_three_numbers(t_struct **a, t_struct **b)
{
	int	d;
	int	e;

	d = (*a)->next->data;
	e = (*a)->next->next->data;
	while (stack_a_is_sorted(a))
	{
		if ((*a)->data > d && d < e && (*a)->data < e)
			sa(a, b);
		if ((*a)->data > d && d > e)
		{
			sa(a, b);
			rra(a, b);
		}
		if ((*a)->data > d && d < e && (*a)->data > e)
			ra(a, b);
		if ((*a)->data < d && d > e && e > (*a)->data)
		{
			sa(a, b);
			ra(a, b);
		}
		if ((*a)->data < d && d > e && e < (*a)->data)
			rra(a, b);
	}
}

int	find_min_value(t_struct **a, int *count)
{
	t_struct	*tmp;
	int			min;

	min = (*a)->data;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = *a;
	*count = 0;
	while (tmp && tmp->data != min)
	{
		(*count)++;
		tmp = tmp->next;
	}
	return (min);
}

void	bottom2(t_struct **a, t_struct **b, int *a_bottom, t_array *ar)
{
	rra(a, b);
	(*a_bottom)--;
	ar->size--;
}
