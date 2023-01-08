/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:08:55 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/04 02:31:07 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_lstnew(int data)
{
	t_struct	*first;

	first = malloc(sizeof(t_struct));
	if (!first)
		return (0);
	first->data = data;
	first->next = NULL;
	return (first);
}

int	ft_lstsize(t_struct *lst)
{
	t_struct	*tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_struct	*ft_lstlast(t_struct *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_struct **lst, t_struct *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_struct **lst, t_struct *new)
{
	t_struct	*newlst;

	newlst = *lst;
	if (*lst)
	{
		newlst = ft_lstlast(newlst);
		newlst->next = new;
	}
	else
		*lst = new;
}
