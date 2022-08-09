/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:04:09 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:04:10 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_rb(t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if ((*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	lst_add_back(&temp, *stack_b);
	*stack_b = temp;
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = temp;
		ft_putstr_fd("pb\n", 1);
	}
}
