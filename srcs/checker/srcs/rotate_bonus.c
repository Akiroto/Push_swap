/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:35:55 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:33:11 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_2;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	tmp_2 = tmp;
	lstlast(tmp_2)->next = (*stack);
	*stack = tmp;
	return (1);
}
