/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instructions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:52:19 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 01:00:01 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_struct **a, t_struct **b)
{
	(void)a;
	if (*b != NULL && (*b)->next != NULL)
		swap(&(*b)->data, &(*b)->next->data);
}

void	pb(t_struct **a, t_struct **b)
{
	t_struct	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, ft_lstnew((*a)->data));
	free(*a);
	*a = tmp;
}

void	rb(t_struct **a, t_struct **b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	(void)a;
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp1 = (*b)->next;
		tmp = ft_lstlast(*b);
		tmp->next = *b;
		(*b)->next = NULL;
		*b = tmp1;
	}
}

void	rrb(t_struct **a, t_struct **b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	(void)a;
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp1 = *b;
		while (tmp1)
		{
			if (tmp1->next->next == NULL)
				break ;
			tmp1 = tmp1->next;
		}
		tmp = ft_lstlast(*b);
		tmp1->next = NULL;
		tmp->next = *b;
		*b = tmp;
	}
}

void	bottom3(t_struct **a, t_struct **b, int *a_bottom)
{
	while (*a_bottom > 0)
	{
		rra(a, b);
		(*a_bottom)--;
	}
}
