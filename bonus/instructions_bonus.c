/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:07:35 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/07 23:43:11 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rrr(t_struct **a, t_struct **b)
{
	rra(a, b);
	rrb(a, b);
}

void	ss(t_struct **a, t_struct **b)
{
	sa(a, b);
	sb(a, b);
}

void	rr(t_struct **a, t_struct **b)
{
	ra(a, b);
	rb(a, b);
}
