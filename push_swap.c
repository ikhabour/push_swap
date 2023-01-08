/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:36:33 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 01:19:04 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printerror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	sort_small_numbers(t_struct **a, t_struct **b)
{
	int	i;
	int	min;

	i = 0;
	while (ft_lstsize(*a) > 3)
	{
		min = find_min_value(a, &i);
		while ((*a)->data != min && i <= ft_lstsize(*a) / 2)
			ra(a, b);
		while ((*a)->data != min && i > ft_lstsize(*a) / 2)
			rra(a, b);
		pb(a, b);
	}
	if (stack_a_is_sorted(a))
		sort_three_numbers(a, b);
	while (*b)
		pa(a, b);
}

void	sort_big_numbers(t_struct **a, t_struct **b, t_array *arr, t_chunk *c)
{
	quick_sort(arr->array, arr->size);
	from_a_to_b(a, b, arr, c);
	from_b_to_a(a, b, arr);
}

void	check_size(t_struct **a, t_struct **b, t_array *arr, t_chunk *c)
{
	arr->size = ft_lstsize(*a);
	if (arr->size == 2)
		sort_two_numbers(a, b);
	if (arr->size <= 16)
		sort_small_numbers(a, b);
	if (arr->size > 16)
		sort_big_numbers(a, b, arr, c);
}

int	main(int argc, char **argv)
{
	t_struct	*a;
	t_struct	*b;
	t_array		*arr;
	t_chunk		*c;
	t_main		var;

	var.j = 1;
	var.i = 1;
	b = NULL;
	c = malloc(sizeof(t_chunk));
	arr = malloc(sizeof(t_array));
	if (argc == 1)
		exit(0);
	validate_arguments(var, argc, argv);
	a = make_stack(argc, argv);
	if (stack_a_is_sorted(&a) == 0)
		exit(0);
	arr->array = store_stack_in_array(&a);
	arr->size = ft_lstsize(a);
	c->mid = arr->size / 2;
	check_size(&a, &b, arr, c);
}
