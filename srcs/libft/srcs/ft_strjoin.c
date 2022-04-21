/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:13:38 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pre;
	char	*suf;
	char	*dest;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	pre = (char *) s1;
	suf = (char *) s2;
	dest = malloc((ft_strlen(pre) + ft_strlen(suf) + 1) * sizeof(*pre));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*pre)
	{
		dest[i] = *pre++;
		i++;
	}
	while (*suf)
	{
		dest[i] = *suf++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
