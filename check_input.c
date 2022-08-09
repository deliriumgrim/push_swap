/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:14:57 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:14:59 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input_help(char **argv, char **input, char **split, int end)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		split = ft_split(argv[j], ' ');
		if (!split)
			ft_exit(input);
		i = 0;
		while (split[i])
		{
			input[end] = ft_strdup(split[i]);
			if (!input[end])
				ft_exit(input);
			i++;
			end++;
		}
		free_split(split);
		j++;
	}
	return (end);
}

int	check_input(char **argv, char **input)
{
	char	**split;
	int		end;

	split = NULL;
	end = 0;
	end = check_input_help(argv, input, split, end);
	return (end);
}

int	if_duplicate(int *numbers, char **input, int j)
{
	static int	cnt;
	int			i;
	int			number;
	int			flag;

	flag = 0;
	i = 0;
	number = ft_atoi(input[j]);
	numbers[cnt] = number;
	while (i <= cnt)
	{
		if (numbers[i] == number)
			flag++;
		if (flag == 2)
		{
			free(numbers);
			return (1);
		}
		i++;
	}
	cnt++;
	return (0);
}

int	input_error_help(char **input, int i, int j, int *numbers)
{
	if (!ft_isdigit(input[j][i]))
	{
		free(numbers);
		return (1);
	}
	return (0);
}

int	input_error(char **input, int argc)
{
	int	i;
	int	j;
	int	*numbers;

	numbers = malloc(sizeof(int *) * argc);
	if (!numbers)
		return (1);
	j = 0;
	while (input[j])
	{
		i = 0;
		while (input[j][i] != '\0')
		{
			if (input[j][i] == '-')
				i++;
			if (input_error_help(input, i, j, numbers) == 1)
				return (1);
			i++;
		}
		if (if_duplicate(numbers, input, j) == 1)
			return (1);
		j++;
	}
	free(numbers);
	return (0);
}
