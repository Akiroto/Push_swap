/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:54:06 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 18:22:28 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*not_lstlast(t_list *lst)
{
	t_list	*tmp_lst;

	if (!lst || !lst->next)
		return (NULL);
	while (lst->next)
	{
		tmp_lst = lst;
		lst = lst->next;
	}
	return (tmp_lst);
}

static int	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	tmp = *stack;
	last = lstlast(tmp);
	not_lstlast(tmp)->next = NULL;
	last->next = tmp;
	*stack = last;
	return (1);
}

int	ft_rra(t_list **stack_a)
{
	ft_printf("rra\n");
	return (ft_reverse_rotate(stack_a));
}

int	ft_rrb(t_list **stack_b)
{
	ft_printf("rrb\n");
	return (ft_reverse_rotate(stack_b));
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	int	i;

	ft_printf("rrr\n");
	i = ft_reverse_rotate(stack_a);
	i += ft_reverse_rotate(stack_b);
	return (i);
}
