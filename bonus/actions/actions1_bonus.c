/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:04:02 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:04:03 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*temp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	lst_add_back(&temp, *stack_a);
	*stack_a = temp;
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	new = lst_new(temp->content);
	new->flag = temp->flag;
	temp = *stack_a;
	while (temp->next)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	lst_add_back(&new, *stack_a);
	*stack_a = new;
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	new = lst_new(temp->content);
	new->flag = temp->flag;
	temp = *stack_b;
	while (temp->next)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	lst_add_back(&new, *stack_b);
	*stack_b = new;
}
