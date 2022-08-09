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

#include "../push_swap.h"

void	write_action(int flag, char *str)
{
	if (flag == 1)
		ft_putstr_fd(str, 1);
}

void	ft_sa(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	if (stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
}

void	ft_ra(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	lst_add_back(&temp, *stack_a);
	*stack_a = temp;
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_stack **stack_a, int flag)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_a)->next == NULL)
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
	write_action(flag, "rra\n");
}

void	ft_rrb(t_stack **stack_b, int flag)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_b)->next == NULL)
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
	write_action(flag, "rrb\n");
}
