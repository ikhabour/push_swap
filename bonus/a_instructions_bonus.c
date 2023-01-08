/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:52:37 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 00:59:58 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_struct **a, t_struct **b)
{
	(void)b;
	if (*a != NULL && (*a)->next != NULL)
		swap(&(*a)->data, &(*a)->next->data);
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
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
