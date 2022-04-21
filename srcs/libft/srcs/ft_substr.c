/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:52:04 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null_str(void)
{
	char	*strmalloc;

	strmalloc = malloc(1 * sizeof(char));
	if (!strmalloc)
		return (NULL);
	strmalloc[0] = '\0';
	return (strmalloc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strmalloc;
	int		i;

	i = (int) start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		strmalloc = ft_null_str();
		return (strmalloc);
	}
	else if (len >= ft_strlen(s))
		strmalloc = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		strmalloc = malloc((len + 1) * sizeof(char));
	if (strmalloc == NULL)
		return (NULL);
	while (s[i] && i - start < len)
	{
		strmalloc[i - start] = s[i];
		i++;
	}
	strmalloc [i - start] = '\0';
	return (strmalloc);
}
