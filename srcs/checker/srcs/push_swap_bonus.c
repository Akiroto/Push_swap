/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:27:13 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 16:55:57 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_issort(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = 1;
	if (stack_b)
		return (0);
	while (tmp)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

static int	verif_push_swap(t_list **stack_a,
			t_list **stack_b, char *gnl_return)
{
	int	verif;

	verif = 0;
	if (!ft_strcmp(gnl_return, "sa\n") || !ft_strcmp(gnl_return, "ss\n"))
		verif += ft_swap(stack_a);
	if (!ft_strcmp(gnl_return, "sb\n") || !ft_strcmp(gnl_return, "ss\n"))
		verif += ft_swap(stack_b);
	if (!ft_strcmp(gnl_return, "pa\n"))
		verif += ft_push(stack_a, stack_b);
	if (!ft_strcmp(gnl_return, "pb\n"))
		verif += ft_push(stack_b, stack_a);
	if (!ft_strcmp(gnl_return, "ra\n") || !ft_strcmp(gnl_return, "rr\n"))
		verif += ft_rotate(stack_a);
	if (!ft_strcmp(gnl_return, "rb\n") || !ft_strcmp(gnl_return, "rr\n"))
		verif += ft_rotate(stack_b);
	if (!ft_strcmp(gnl_return, "rra\n") || !ft_strcmp(gnl_return, "rrr\n"))
		verif += ft_reverse_rotate(stack_a);
	if (!ft_strcmp(gnl_return, "rrb\n") || !ft_strcmp(gnl_return, "rrr\n"))
		verif += ft_reverse_rotate(stack_b);
	return (verif);
}

void	free_all(char *gnl_return, t_list **stack_a, t_list **stack_b)
{
	free(gnl_return);
	lstclear(stack_a);
	lstclear(stack_b);
	free(stack_a);
	free(stack_b);
}

char	*read_operation(t_list **stack_a, t_list **stack_b)
{
	int		verif;
	char	*gnl_return;

	gnl_return = get_next_line(0);
	while (gnl_return)
	{
		verif = verif_push_swap(stack_a, stack_b, gnl_return);
		if (verif <= 0)
		{
			ft_printf("Error\n");
			free_all(gnl_return, stack_a, stack_b);
			exit (1);
		}
		free(gnl_return);
		gnl_return = get_next_line(0);
	}
	return (gnl_return);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*gnl_return;

	if (argc > 1)
	{
		stack_a = malloc(sizeof(t_list *));
		*stack_a = ft_parsing(argc, argv, stack_a);
		stack_b = malloc(sizeof(t_list *));
		*stack_b = NULL;
		ft_index(*stack_a);
		gnl_return = read_operation(stack_a, stack_b);
		if (ft_issort(*stack_a, *stack_b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_all(gnl_return, stack_a, stack_b);
	}
}
