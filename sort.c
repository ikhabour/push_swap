/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:13:18 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/07 18:17:44 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_struct **b, int max)
{
	t_struct	*tmp;
	int			count;

	tmp = *b;
	count = 0;
	while (tmp->data != max && tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	function(t_struct **b, int max)
{
	t_struct	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->data == max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	from_b_to_a(t_struct **a, t_struct **b, t_array *ar)
{
	t_struct	*tmp;
	int			count;
	int			a_bottom;

	tmp = *b;
	count = 0;
	a_bottom = 0;
	while (*b)
	{
		if (function(b, ar->array[ar->size - 1]) == 1)
		{
			if ((*b)->data == ar->array[ar->size - 1])
			{
				pa(a, b);
				ar->size--;
			}
			else if (a_bottom == 0 || (*b)->data > ft_lstlast(*a)->data)
				bottom(a, b, &a_bottom);
			else if ((*b)->data != ar->array[ar->size - 1])
				rb_or_rrb(a, b, ar, count);
		}
		else
			bottom2(a, b, &a_bottom, ar);
	}
	bottom3(a, b, &a_bottom);
}

int	check_numbers(t_struct **a, t_chunk *c, t_array *ar, int *index)
{
	t_struct	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->data >= ar->array[c->start] && tmp->data <= ar->array[c->end])
			return (1);
		else
		{
			tmp = tmp->next;
			(*index)++;
		}
	}
	return (0);
}

void	from_a_to_b(t_struct **a, t_struct **b, t_array *ar, t_chunk *c)
{
	int	index;

	check_list_size(c, ar);
	while (*a)
	{
		index = 0;
		while (check_numbers(a, c, ar, &index) == 1)
		{
			while (!((*a)->data >= ar->array[c->start]
					&& (*a)->data <= ar->array[c->end])
				&& index <= ft_lstsize(*a) / 2)
				ra(a, b);
			while (!((*a)->data >= ar->array[c->start]
					&& (*a)->data <= ar->array[c->end])
				&& index > ft_lstsize(*a) / 2)
				rra(a, b);
			pb(a, b);
			if ((*b)->data < ar->array[c->mid])
				rb(a, b);
			index = 0;
		}
		ft_range(c, ar);
	}
}
