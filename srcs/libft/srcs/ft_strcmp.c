/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:08:46 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 15:56:43 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *const_str1, const char *const_str2)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *)const_str1;
	str2 = (char *)const_str2;
	i = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[i] || str2[i])
	{
		if (!str1[i] || !str2[i] || str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}
