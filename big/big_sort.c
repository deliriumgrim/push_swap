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

#include "../push_swap.h"

void	big_sort_b(t_stack **stack_b, t_stack **stack_a)
{
	while (*stack_b)
	{
		if (!(*stack_b))
			break ;
		if ((*stack_b)->content != find_large(stack_b)
			&& !sort_steps(stack_b))
			ft_rb(stack_b, 1);
		else if ((*stack_b)->content != find_large(stack_b)
			&& sort_steps(stack_b))
			ft_rrb(stack_b, 1);
		else if ((*stack_b)->content == find_large(stack_b))
			ft_pa(stack_a, stack_b);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int action)
{
	int	count;

	count = 0;
	while (*stack_a)
	{
		if (count > 1 && (*stack_a)->index <= count)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b, 1);
			count++;
		}
		else if ((*stack_a)->index <= (count + action))
		{
			ft_pb(stack_a, stack_b);
			count++;
		}
		else if ((*stack_a)->index >= count)
			ft_ra(stack_a, 1);
	}
	big_sort_b(stack_b, stack_a);
	lst_free(stack_a);
	lst_free(stack_b);
}
