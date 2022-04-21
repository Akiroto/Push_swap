/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:25 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*bi;
	char	*li;

	bi = (char *) big;
	li = (char *) little;
	i = 0;
	if (li[0] == '\0')
		return (bi);
	while (bi[i])
	{
		j = 0;
		k = i;
		while (bi[k] == li[j] && k < len)
		{
			j++;
			if (li[j] == '\0')
				return (&bi[k - j + 1]);
			k++;
		}
		i++;
	}
	return (NULL);
}
