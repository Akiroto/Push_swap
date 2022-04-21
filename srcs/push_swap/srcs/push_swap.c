/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:41:39 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 11:33:22 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **stack_a)
{
	if (lstsize(*stack_a) < 6)
		ft_small_sort(stack_a);
	else
		ft_big_sort(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;

	if (argc > 1)
	{
		stack_a = malloc(sizeof(t_list *));
		*stack_a = ft_parsing(argc, argv, stack_a);
		ft_index(*stack_a);
		sort(stack_a);
		lstclear(stack_a);
		free(stack_a);
	}
}

// ? Error :
// ? 2- Malloc fail on ft_strjoin_free -> ft_parse || '\0' arg -> ft_parse
// ? 3- Exit while ft_error -> Doublon || Split fail
// ? 4- Exit while ft_error -> is Not Only Digit
// ? 5- Exit while ft_error -> Malloc fail while lstnew
// ? 6- Exit while ft_push -> One of the stack is NULL   <- Can't happen
