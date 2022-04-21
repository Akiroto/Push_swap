/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:13:46 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:41:38 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_swap(t_list **stack)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	tmp_1 = *stack;
	tmp_2 = tmp_1->next;
	tmp_1->next = tmp_2->next;
	tmp_2->next = tmp_1;
	*stack = tmp_2;
	return (1);
}
