/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:55:31 by ikhabour          #+#    #+#             */
/*   Updated: 2023/01/08 01:01:17 by ikhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	printerror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	do_instructions(char *instruction, t_struct **a, t_struct **b)
{
	if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a, b);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(a, b);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a, b);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(a, b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		printerror();
}

void	read_instructions(int fd, t_struct **a, t_struct **b)
{
	char	*instruction;

	instruction = get_next_line(fd);
	while (instruction != NULL)
	{
		do_instructions(instruction, a, b);
		free(instruction);
		instruction = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_struct	*a;
	t_struct	*b;
	t_main		var;

	var.j = 1;
	var.i = 1;
	b = NULL;
	if (argc == 1)
		exit(0);
	while (var.j < argc)
	{
		var.tmp = ft_split(argv[var.j], ' ');
		check_arguments(var.tmp);
		ft_free_tmp(var.tmp);
		var.j++;
	}
	a = make_stack(argc, argv);
	read_instructions(0, &a, &b);
	if (stack_a_is_sorted(&a) == 0 && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
