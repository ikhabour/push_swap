/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:21:30 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/06 23:17:32 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *array, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap(&array[i], &array[j]);
	return (i);
}

void	quick_sort_recursion(int *array, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quick_sort_recursion(array, low, pivot_index - 1);
		quick_sort_recursion(array, pivot_index + 1, high);
	}
}

void	quick_sort(int *array, int length)
{
	quick_sort_recursion(array, 0, length - 1);
}

void	validate_arguments(t_main var, int argc, char **argv)
{
	while (var.j < argc)
	{
		var.tmp = ft_split(argv[var.j], ' ');
		check_arguments(var.tmp);
		ft_free_tmp(var.tmp);
		var.j++;
	}
}
