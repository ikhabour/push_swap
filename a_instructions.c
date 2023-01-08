/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:32:33 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 00:59:41 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_struct **a, t_struct **b)
{
	(void)b;
	if (*a != NULL && (*a)->next != NULL)
	{
		swap(&(*a)->data, &(*a)->next->data);
		write(1, "sa\n", 3);
	}
}

void	pa(t_struct **a, t_struct **b)
{
	t_struct	*tmp;

	if (!*b)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, ft_lstnew((*b)->data));
	free(*b);
	*b = tmp;
	write(1, "pa\n", 3);
}

void	ra(t_struct **a, t_struct **b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	(void)b;
	if (*a != NULL && (*a)->next != NULL)
	{
		tmp1 = (*a)->next;
		tmp = ft_lstlast(*a);
		tmp->next = *a;
		(*a)->next = NULL;
		*a = tmp1;
		write(1, "ra\n", 3);
	}
}

void	rra(t_struct **a, t_struct **b)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	(void)b;
	tmp1 = *a;
	if (*a != NULL && (*a)->next != NULL)
	{
		while (tmp1)
		{
			if (tmp1->next->next == NULL)
				break ;
			tmp1 = tmp1->next;
		}
		tmp = ft_lstlast(*a);
		tmp1->next = NULL;
		tmp->next = *a;
		*a = tmp;
		write(1, "rra\n", 4);
	}
}
