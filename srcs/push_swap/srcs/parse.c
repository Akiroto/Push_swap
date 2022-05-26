/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:10:03 by lseiller          #+#    #+#             */
/*   Updated: 2022/05/26 13:08:29 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(char **nbr, t_list **stack_a, int nb, int index)
{
	lstclear(stack_a);
	free(stack_a);
	ft_putstr_fd("Error\n", 1);
	ft_free_split(nbr, index);
	exit (nb);
}

static t_list	*ft_create_stack(char *arg, t_list **stack_a)
{
	t_list	*tmp;
	char	**nbr;
	int		i;

	*stack_a = NULL;
	tmp = NULL;
	i = 0;
	nbr = ft_split(arg, ' ');
	free(arg);
	if (!nbr || ft_isdoublon(nbr))
		ft_error(nbr, stack_a, 3, i);
	while (nbr[i])
	{
		if (!ft_isstrdigit(nbr[i]) || !ft_isoverflow(nbr[i]))
			ft_error(nbr, stack_a, 4, i);
		tmp = lstnew(nbr[i]);
		if (!tmp)
			ft_error(nbr, stack_a, 5, i);
		lstadd_back(stack_a, tmp);
		i++;
	}
	free(nbr);
	return (*stack_a);
}

t_list	*ft_parsing(int argc, char **argv, t_list **stack_a)
{
	int		i;
	char	*arg_number;

	i = 1;
	arg_number = ft_strdup(argv[i++]);
	while (i < argc)
	{
		if (!*argv[i - 1] || !arg_number)
		{
			ft_putstr_fd("Error\n", 1);
			free(arg_number);
			free(stack_a);
			exit(2);
		}
		arg_number = ft_strjoin_free(arg_number, argv[i]);
		i++;
	}
	if (!*argv[i - 1] || !arg_number)
	{
		ft_putstr_fd("Error\n", 1);
		free(arg_number);
		free(stack_a);
		exit(2);
	}
	return (ft_create_stack(arg_number, stack_a));
}
