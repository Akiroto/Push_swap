/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:40 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 18:25:14 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_first_nb(t_list **stack_a, t_list **stack_b)
{
	int	push;

	push = 0;
	while (!ft_issort(stack_a, (t_list **) NULL, 1) && lstsize(*stack_a) != 3)
	{
		if ((*stack_a)->index == 1)
		{
			ft_pb(stack_b, stack_a);
			push = 1;
		}
		else if (push == 1 && (*stack_a)->index == 2)
			ft_pb(stack_b, stack_a);
		else if ((push == 0 && find_pos(*stack_a, 1) < 3)
			|| (push == 1 && find_pos(*stack_a, 2) < 3))
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

static void	sort_small_stack(t_list **stack_a)
{
	while (!ft_issort(stack_a, (t_list **) NULL, 1))
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
		{
			if ((*stack_a)->next->next)
			{
				if ((*stack_a)->index > (*stack_a)->next->next->index)
					ft_ra(stack_a);
				else
					ft_sa(stack_a);
			}
			else
				ft_sa(stack_a);
		}
		else if ((*stack_a)->index < (*stack_a)->next->index)
			ft_rra(stack_a);
	}
}

void	ft_small_sort(t_list **stack_a)
{
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	if (lstsize(*stack_a) > 3)
		push_b_first_nb(stack_a, stack_b);
	sort_small_stack(stack_a);
	if (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	free(stack_b);
}
