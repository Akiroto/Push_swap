/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:01:07 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:33:37 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

int	ft_push(t_list **stack_to_push, t_list **stack_to_pull)
{
	t_list	*tmp;

	if (!stack_to_pull || !*stack_to_pull)
		return (1);
	tmp = *stack_to_pull;
	*stack_to_pull = tmp->next;
	lstadd_front(stack_to_push, tmp);
	return (1);
}
