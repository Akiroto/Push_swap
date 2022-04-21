/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:41:55 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:02:19 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_find_position(t_list *stack_a, int i, int small)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (ft_atoi(tmp->content) < small && tmp->index == 0)
			small = ft_atoi(tmp->content);
		tmp = tmp->next;
	}
	while (stack_a && ft_atoi(stack_a->content) != small)
		stack_a = stack_a->next;
	if (stack_a)
		stack_a->index = i;
}

void	ft_index(t_list *stack_a)
{
	int		i;
	int		small;
	t_list	*tmp;

	i = 1;
	small = 0;
	while (i < lstsize(stack_a) + 1)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (tmp->index == 0)
				small = ft_atoi(tmp->content);
			tmp = tmp->next;
		}
		ft_find_position(stack_a, i, small);
		i++;
	}
}
