/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:15:56 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 00:01:33 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	check_arguments(char **split_arg)
{
	int	i;

	i = 0;
	while (split_arg[i])
	{
		if (ft_isdigit(split_arg[i]) == 0)
			printerror();
		i++;
	}
	if (i == 0)
		printerror();
}

int	stack_a_is_sorted(t_struct **a)
{
	t_struct	*tmp;

	tmp = *a;
	while (tmp && tmp->next && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	return (1);
}

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
