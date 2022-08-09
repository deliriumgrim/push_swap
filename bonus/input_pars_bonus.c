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

#include "checker_bonus.h"

void	error(t_stack **stack_a, t_stack **stack_b)
{
	lst_free(stack_a);
	lst_free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	commands(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "pa\n", 3))
		ft_pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "sa\n", 3))
		ft_sa(stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_sb(stack_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_ra(stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rb(stack_b);
	else if (!ft_strncmp(line, "rra\n", 3))
		ft_rra(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 3))
		ft_rrb(stack_b);
	else if (!ft_strncmp(line, "rrr\n", 3))
		ft_rrr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	read_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!commands(line, stack_a, stack_b))
			error(stack_a, stack_b);
		free(line);
	}
}
