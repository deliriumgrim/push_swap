/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:08:43 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:08:44 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest_a(stack_a, stack_b);
	sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest_a(stack_a, stack_b);
	push_smallest_a(stack_a, stack_b);
	sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	sort_three_utils(t_stack **stack_a, int *numbers)
{
	if (numbers[0] > numbers[1] && numbers[1] > numbers[2])
	{
		ft_ra(stack_a, 1);
		ft_sa(stack_a, 1);
	}
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[0] < numbers[2])
	{
		ft_sa(stack_a, 1);
		ft_ra(stack_a, 1);
	}
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*temp;
	int		numbers[3];
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		numbers[i] = temp->content;
		temp = temp->next;
		i++;
	}
	if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] < numbers[2])
		ft_sa(stack_a, 1);
	else if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] > numbers[2])
		ft_ra(stack_a, 1);
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[0] > numbers[2])
		ft_rra(stack_a, 1);
	else
		sort_three_utils(stack_a, numbers);
}

void	small_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a, 1);
		lst_free(stack_a);
	}
	if (argc == 3)
	{
		sort_three(stack_a);
		lst_free(stack_a);
	}
	else if (argc == 4)
	{
		sort_four(stack_a, stack_b);
		lst_free(stack_a);
	}
	else if (argc == 5)
	{
		sort_five(stack_a, stack_b);
		lst_free(stack_a);
	}
}
