/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:22:02 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:18:42 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split, int i)
{
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_isdoublon(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	ft_atoi_long(const char *nptr)
{
	char	*atoi;
	long	n;
	long	final;

	n = 1;
	final = 0;
	atoi = (char *)nptr;
	while ((*atoi >= 9 && *atoi <= 13) || *atoi == ' ')
		atoi++;
	if (*atoi == '-' || *atoi == '+')
	{
		if (*atoi == '-')
			n = -1;
		atoi++;
	}
	while (*atoi >= '0' && *atoi <= '9')
		final = final * 10 + (*atoi++ - 48);
	return (final * n);
}

int	ft_isoverflow(char *nbr)
{
	int	is_negative;

	is_negative = 0;
	if (*nbr == '-')
	{
		nbr++;
		is_negative = 1;
	}
	while (*nbr && *nbr == '0')
		nbr++;
	if (ft_strlen(nbr) > 12)
		return (0);
	if ((is_negative == 0 && ft_atoi_long(nbr) > 2147483647)
		|| (is_negative == 1 && ft_atoi_long(nbr) > 2147483648))
		return (0);
	return (1);
}

int	ft_isstrdigit(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
			return (0);
		if (str[i] == '-')
		{
			j = 0;
			if (str[i] && (str[i + 1] < '0' || str[i + 1] > '9'))
				return (0);
			while (j < i)
			{
				if (str[i - j] != '0')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
