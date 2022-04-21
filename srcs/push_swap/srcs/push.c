/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:01:07 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 14:49:32 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

static int	ft_push(t_list **stack_to_push, t_list **stack_to_pull)
{
	t_list	*tmp;

	if (!stack_to_pull || !*stack_to_pull)
		return (0);
	tmp = *stack_to_pull;
	*stack_to_pull = tmp->next;
	lstadd_front(stack_to_push, tmp);
	return (1);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_printf("pa\n");
	return (ft_push(stack_a, stack_b));
}

int	ft_pb(t_list **stack_b, t_list **stack_a)
{
	ft_printf("pb\n");
	return (ft_push(stack_b, stack_a));
}
