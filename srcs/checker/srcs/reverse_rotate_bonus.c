/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:54:06 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:33:51 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_list	*not_lstlast(t_list *lst)
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

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	tmp = *stack;
	last = lstlast(tmp);
	not_lstlast(tmp)->next = NULL;
	last->next = tmp;
	*stack = last;
	return (1);
}
