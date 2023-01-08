/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:52:35 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 00:01:30 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_duplicates(t_struct **stack)
{
	t_struct	*tmp;
	t_struct	*tmp1;

	tmp = *stack;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->data == tmp1->data)
				printerror();
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

t_struct	*make_stack(int argc, char **argv)
{
	t_struct	*stack;
	char		**tmp;
	int			i;
	int			x;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		x = 0;
		tmp = ft_split(argv[i], ' ');
		while (tmp[x])
		{
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(tmp[x])));
			x++;
		}
		ft_free_tmp(tmp);
		i++;
	}
	check_duplicates(&stack);
	return (stack);
}
