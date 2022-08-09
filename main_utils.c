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

#include "push_swap.h"

void	set_flag(t_stack **stack, int x)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->flag = x;
			break ;
		}
		temp->flag = x;
		temp = temp->next;
	}
}

void	find_smallest(t_stack **stack, int x, int i)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->content <= x && temp->flag != -1)
			x = temp->content;
		temp = temp->next;
	}
	temp = *stack;
	while (temp && temp->content != x)
	{
		temp = temp->next;
	}
	temp->index = i;
	temp->flag = -1;
}

void	indexing(int argc, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		find_smallest(stack_a, INT_MAX, i);
		i++;
	}
}

int	check_len_input_utils(char **argv, char **split, int i, int j)
{
	int	g;

	g = 0;
	while (argv[i])
	{
		if (argv[i][j] == '\0')
			ft_exit(NULL);
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_exit(split);
		j = 0;
		while (split[j])
		{
			j++;
			g++;
		}
		j = 0;
		free_split(split);
		i++;
	}
	return (g);
}

char	**check_len_input(char **argv, char **input)
{
	int		g;
	int		i;
	int		j;
	char	**split;

	split = NULL;
	i = 0;
	j = 0;
	g = check_len_input_utils(argv, split, i, j);
	input = ft_calloc(g, sizeof(char *));
	if (!input)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (input);
}
