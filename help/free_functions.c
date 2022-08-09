/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:04:15 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:04:18 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_free(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		if (temp == NULL)
			break ;
		*stack = temp;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split != NULL)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
