/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:55:37 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_push(t_list **stack_a, t_list **stack_b, int size, int operation)
{
	ft_rotate_to_index(stack_b, size, operation);
	ft_pa(stack_a, stack_b);
	return (size - 1);
}

int	double_push(t_list **stack_a, t_list **stack_b, int size, int operation)
{
	ft_rotate_to_index(stack_b, size - 1, operation);
	ft_pa(stack_a, stack_b);
	ft_rotate_to_index(stack_b, size, operation);
	ft_pa(stack_a, stack_b);
	ft_sa(stack_a);
	return (size - 2);
}

int	double_push_switched(t_list **stack_a, t_list **stack_b,
					int size, int operation)
{
	if (operation == RRB)
	{
		ft_rotate_to_index(stack_b, size - 1, RRB);
		ft_pa(stack_a, stack_b);
		ft_rotate_to_index(stack_b, size, RB);
		ft_pa(stack_a, stack_b);
		ft_sa(stack_a);
	}
	else if (operation == RB)
	{
		ft_rotate_to_index(stack_b, size - 1, RB);
		ft_pa(stack_a, stack_b);
		ft_rotate_to_index(stack_b, size, RRB);
		ft_pa(stack_a, stack_b);
		ft_sa(stack_a);
	}
	return (size - 2);
}

int	case_pos_switched(t_list **stack_a, t_list **stack_b, int size)
{
	int	position_a;
	int	position_b;

	position_a = find_pos(*stack_b, size);
	position_b = find_pos(*stack_b, size - 1);
	if (position_a <= size / 2 && position_a <= size - position_b)
		size = simple_push(stack_a, stack_b, size, RB);
	else if (position_a <= size / 2 && position_a > size - position_b)
		size = double_push_switched(stack_a, stack_b, size, RRB);
	else if (position_a > size / 2 && position_b <= size - position_a)
		size = double_push_switched(stack_a, stack_b, size, RB);
	else if ((position_a > size / 2 && position_b > size - position_a))
		size = simple_push(stack_a, stack_b, size, RRB);
	return (size);
}
