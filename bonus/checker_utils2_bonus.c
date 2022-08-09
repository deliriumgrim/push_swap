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

int	if_sort(int argc, t_stack **stack, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp && *stack_b == NULL)
	{
		if (temp->next != NULL && temp->content < temp->next->content)
		{
			temp = temp->next;
			i++;
		}
		else if (temp->next == NULL)
		{
			i++;
			if (i == argc)
				return (1);
		}
		else
			break ;
	}
	return (0);
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
