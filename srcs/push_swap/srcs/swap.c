/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:13:46 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	tmp_1 = *stack;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_2->next;
	tmp_2->next = tmp_1;
	*stack = tmp_2;
	return (1);
}

int	ft_sa(t_list **stack_a)
{
	ft_printf("sa\n");
	return (ft_swap(stack_a));
}

int	ft_sb(t_list **stack_b)
{
	ft_printf("sb\n");
	return (ft_swap(stack_b));
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_swap(stack_a);
	i += ft_swap(stack_b);
	ft_printf("ss\n");
	return (i - 1);
}
