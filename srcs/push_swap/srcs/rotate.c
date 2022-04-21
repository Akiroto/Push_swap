/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:35:55 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstlast(t_list *lst)
{
	t_list	*tmp_lst;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp_lst = lst;
		lst = lst->next;
	}
	return (tmp_lst);
}

static int	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_2;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	tmp_2 = tmp;
	lstlast(tmp_2)->next = (*stack);
	*stack = tmp;
	return (1);
}

int	ft_ra(t_list **stack_a)
{
	ft_printf("ra\n");
	return (ft_rotate(stack_a));
}

int	ft_rb(t_list **stack_b)
{
	ft_printf("rb\n");
	return (ft_rotate(stack_b));
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	int	i;

	ft_printf("rr\n");
	i = ft_rotate(stack_a);
	i += ft_rotate(stack_b);
	return (i);
}
