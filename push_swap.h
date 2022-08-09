/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:17:20 by drumfred          #+#    #+#             */
/*   Updated: 2022/03/10 15:18:13 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				flag;
	struct s_stack	*next;
}	t_stack;

int		check_input(char **argv, char **input);
int		input_error(char **input, int argc);
void	indexing(int argc, t_stack **stack_a);
char	**check_len_input(char **argv, char **input);
void	ft_exit(char **input);

void	free_split(char **split);
void	lst_free(t_stack **stack);

t_stack	*fill_list(int argc, char **input);
void	lst_add_back(t_stack **head, t_stack *new);
t_stack	*lst_new(long content);
int		lst_size(t_stack **stack);
void	find_smallest(t_stack **stack, int x, int i);

int		if_sort(int argc, t_stack **stack);
void	sort(int argc, t_stack **stack_a, t_stack **stack_b);
void	small_sort(int argc, t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);

void	big_sort(t_stack **stack_a, t_stack **stack_b, int action);
int		sort_steps(t_stack **stack_b);
int		find_large(t_stack **stack);

void	push_smallest_a(t_stack **stack_a, t_stack **stack_b);
void	set_flag(t_stack **stack, int x);

void	ft_sa(t_stack **stack_a, int flag);
void	ft_ra(t_stack **stack_a, int flag);
void	ft_rra(t_stack **stack_a, int flag);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_rb(t_stack **stack_b, int flag);
void	ft_rrb(t_stack **stack_b, int flag);
#endif
