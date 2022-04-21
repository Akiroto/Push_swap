/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:03:34 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	should_swap_or_rotate(t_list **stack_a, t_list **stack_b, int inc_pool,
			int pool)
{
	const int	size = lstsize(*stack_a) + lstsize(*stack_b);
	const int	nb_pool = 5 * (1 + 0.12 * (size / 100));

	if (((*stack_b)->index <= pool - size / nb_pool + (size / nb_pool) / 2))
	{
		if ((*stack_b)->next && ((*stack_b)->index < (*stack_b)->next->index))
		{
			if ((*stack_a) && (*stack_a)->next
				&& (*stack_a)->next->index <= pool
				&& (*stack_a)->index <= pool + size / nb_pool)
				ft_ss(stack_a, stack_b);
			else
				ft_sb(stack_b);
		}
	}
	else
	{
		if (*stack_a && ((*stack_a)->index > pool
				&& !(inc_pool == size / nb_pool
					&& (*stack_a)->index <= pool + size / nb_pool)))
			ft_rr(stack_a, stack_b);
		else if (*stack_a)
			ft_rb(stack_b);
	}
}
