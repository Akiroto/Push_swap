/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:29:30 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 18:25:23 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->index > tmp->next->index && tmp->next->index == 1)
		{
			while (tmp)
			{
				if (tmp->next && (tmp->next->index != i))
					return (-1);
				tmp = tmp->next;
				i++;
			}
			return (1);
		}
		else if (tmp->next && tmp->index > tmp->next->index
			&& tmp->next->index != 1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static void	rotate_to_sort(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (!ft_issort(stack_a, stack_b, 0))
	{
		while (tmp->index != 1)
		{
			tmp = tmp->next;
			i++;
		}
		if (size_a - i > size_a / 2)
		{
			if ((*stack_a)->index == (*stack_a)->next->index + 1
				&& (*stack_a)->next->index < (*stack_a)->next->next->index)
				ft_sa(stack_a);
			else
				ft_ra(stack_a);
		}
		else
			ft_rra(stack_a);
	}
}

static void	pool_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	int			pool;
	int			inc_pool;
	const int	nb_pool = 5 * (1 + 0.12 * (size / 100));

	pool = 0;
	while ((*stack_a))
	{
		if (pool == 0 || inc_pool == size / nb_pool)
		{
			pool += size / nb_pool;
			inc_pool = 1;
		}
		while ((*stack_a)->index > pool)
		{
			if ((*stack_a)->next->index <= pool
				&& (*stack_a)->index <= pool + size / nb_pool
				&& inc_pool == size / nb_pool)
				ft_sa(stack_a);
			else
				ft_ra(stack_a);
		}
		ft_pb(stack_b, stack_a);
		should_swap_or_rotate(stack_a, stack_b, inc_pool, pool);
		inc_pool++;
	}
}

static void	sort_pool(t_list **stack_a, t_list **stack_b, int size)
{
	int	position_a;
	int	position_b;

	while (!ft_issort(stack_a, stack_b, 0))
	{
		position_a = find_pos(*stack_b, size);
		position_b = find_pos(*stack_b, size - 1);
		if (position_a <= size / 2 && position_b <= size / 2)
		{
			if (position_a < position_b)
				size = simple_push(stack_a, stack_b, size, RB);
			else
				size = double_push(stack_a, stack_b, size, RB);
		}
		else if (position_a > size / 2 && position_b > size / 2)
		{
			if (position_a > position_b)
				size = simple_push(stack_a, stack_b, size, RRB);
			else
				size = double_push(stack_a, stack_b, size, RRB);
		}
		else
			size = case_pos_switched(stack_a, stack_b, size);
	}
}

void	ft_big_sort(t_list **stack_a)
{
	t_list		**stack_b;
	int			size_stack;

	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	size_stack = lstsize(*stack_a);
	if (check_sort(stack_a) == 1)
		rotate_to_sort(stack_a, stack_b, size_stack);
	else if (check_sort(stack_a) == -1)
	{
		pool_to_b(stack_a, stack_b, size_stack);
		sort_pool(stack_a, stack_b, size_stack);
	}
	free(stack_b);
}
