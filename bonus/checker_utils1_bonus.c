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
