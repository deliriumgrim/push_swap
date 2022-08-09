/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:04:23 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:04:24 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	lst_add_back(t_stack **head, t_stack *new)
{
	t_stack	*current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_stack	*lst_new(long content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->index = -1;
	head->flag = 0;
	head->next = NULL;
	return (head);
}

t_stack	*fill_list(int argc, char **input)
{
	int		i;
	t_stack	*head;
	t_stack	*temp;

	i = 0;
	head = NULL;
	temp = NULL;
	while (i < argc)
	{
		temp = lst_new(ft_atoi(input[i]));
		if (temp == NULL)
		{
			lst_free(&head);
			break ;
		}
		lst_add_back(&head, temp);
		i++;
	}
	free_split(input);
	return (head);
}
