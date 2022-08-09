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

int	sort_steps(t_stack **stack_b)
{
	t_stack	*temp;
	int		med;
	int		count;

	med = lst_size(stack_b) / 2;
	temp = *stack_b;
	count = 0;
	while (temp->content != find_large(stack_b))
	{
		temp = temp->next;
		count++;
	}
	if (count < med)
		return (0);
	return (1);
}

int	find_large(t_stack **stack)
{
	t_stack	*temp;
	int		x;

	temp = *stack;
	x = temp->content;
	while (temp != NULL)
	{
		if (temp->content > x)
			x = temp->content;
		temp = temp->next;
	}
	return (x);
}
