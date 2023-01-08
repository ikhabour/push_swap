/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:22:31 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/06 20:05:37 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ss(t_struct **a, t_struct **b)
{
	sa(a, b);
	sb(a, b);
	write(1, "ss\n", 3);
}

void	rr(t_struct **a, t_struct **b)
{
	ra(a, b);
	rb(a, b);
	write(1, "rr\n", 3);
}

void	rrr(t_struct **a, t_struct **b)
{
	rra(a, b);
	rrb(a, b);
	write(1, "rrr\n", 4);
}

void	sort_two_numbers(t_struct **a, t_struct **b)
{
	int	c;

	c = (*a)->next->data;
	if ((*a)->data > c)
		sa(a, b);
}
