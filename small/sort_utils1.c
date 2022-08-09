/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:50 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:07:53 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_smallest_a_utils(t_stack **stack_a, int i, int n)
{
	if (n < 3)
	{
		i = 0;
		while (i < n)
		{
			ft_ra(stack_a, 1);
			i++;
		}
	}
	else
	{
		while (i >= n)
		{
			ft_rra(stack_a, 1);
			i--;
		}
	}
}

void	push_smallest_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		x;
	int		n;
	t_stack	*temp;

	i = 0;
	n = 0;
	temp = *stack_a;
	x = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		i++;
		if (x > temp->content)
		{
			n = i;
			x = temp->content;
		}
	}
	if (n != 0)
		push_smallest_a_utils(stack_a, i, n);
	ft_pb(stack_a, stack_b);
}
