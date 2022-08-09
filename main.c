/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:16:19 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:16:21 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_exit(char **input)
{
	free_split(input);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	main_help(t_stack **stack_a, char **input, int argc)
{
	*stack_a = NULL;
	if (input_error(input, argc) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_split(input);
		return (0);
	}
	*stack_a = fill_list(argc, input);
	indexing(argc, stack_a);
	set_flag(stack_a, 0);
	if (!*stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	stack_b = NULL;
	input = NULL;
	if (argc == 1)
		return (0);
	input = check_len_input(argv, input);
	argc = check_input(argv, input);
	if (main_help(&stack_a, input, argc) == 0)
		return (0);
	if (if_sort(argc, &stack_a) == 1)
	{
		lst_free(&stack_a);
		return (0);
	}
	sort(argc, &stack_a, &stack_b);
	return (0);
}
