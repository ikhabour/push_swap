/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:25:01 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/04 21:51:25 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

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

int	*store_stack_in_array(t_struct **a)
{
	t_struct	*tmp;
	int			*array;
	int			i;

	array = malloc((ft_lstsize(*a) + 1) * sizeof(int));
	i = 0;
	tmp = *a;
	while (tmp)
	{
		array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

void	bottom(t_struct **a, t_struct **b, int *a_bottom)
{
	pa(a, b);
	ra(a, b);
	(*a_bottom)++;
}
