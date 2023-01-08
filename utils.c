/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:10:46 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/06 23:17:28 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i && !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		printerror();
	return (result);
}

void	ft_range(t_chunk *c, t_array *ar)
{
	c->start -= c->offset;
	c->end += c->offset;
	if (c->end > ar->size - 1)
		c->end = ar->size - 1;
	if (c->start < 0)
		c->start = 0;
}

void	check_list_size(t_chunk *c, t_array *ar)
{
	if (ar->size <= 250)
		c->offset = ar->size / 8;
	else
		c->offset = ar->size / 18;
	c->start = c->mid - c->offset;
	c->end = c->mid + c->offset;
}

void	rb_or_rrb(t_struct **a, t_struct **b, t_array *ar, int count)
{
	count = find_max_index(b, ar->array[ar->size - 1]);
	if (count <= ft_lstsize(*b) / 2)
		rb(a, b);
	if (count > ft_lstsize(*b) / 2)
		rrb(a, b);
}
