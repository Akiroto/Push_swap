/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:48 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issort(t_list **stack_a, t_list **stack_b, int sort)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	if (sort == 1)
		i = tmp->index;
	else
		i = 1;
	if (stack_b && *stack_b)
		return (0);
	while (tmp)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	find_pos(t_list *stack, int size)
{
	int	i;

	i = 0;
	if (size <= 0 || !stack)
		return (-1);
	while (stack && stack->index != size)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_rotate_to_index(t_list **stack, int size, int op)
{
	if (size <= 0 || !stack || !*stack)
		return ;
	while ((*stack)->index != size)
	{
		if (op == RRB)
			ft_rrb(stack);
		else if (op == RB)
		{
			if ((*stack)->next->index == size && (*stack)->index == size - 1)
				ft_sb(stack);
			else
				ft_rb(stack);
		}
	}
}
