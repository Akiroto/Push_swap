/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:37:25 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_debut(char const *s1, char const *set)
{
	int	i;
	int	debut;

	i = 0;
	debut = 0;
	while (set[i])
	{
		while (s1[debut] == set[i])
		{
			debut++;
			i = -1;
		}
		i++;
	}
	return (debut);
}

static int	ft_fin(char const *s1, char const *set)
{
	int	i;
	int	fin;

	i = 0;
	fin = ft_strlen(s1);
	if (!set[i])
		return (fin);
	while (set[i])
	{
		while (s1[fin] == set[i] || s1[fin] == '\0')
		{
			fin--;
			i = -1;
		}
		i++;
	}
	return (fin + 1);
}

static char	*ft_jtemalloc(int nb)
{
	char	*tracasse;

	if (nb <= 0)
	{
		tracasse = (char *)malloc(sizeof(char));
		if (tracasse == NULL)
			return (tracasse);
		tracasse[0] = '\0';
	}
	else
	{
		tracasse = (char *)malloc((nb + 1) * sizeof(char));
		if (tracasse == NULL)
			return (NULL);
	}
	return (tracasse);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		nb;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	nb = ft_fin(s1, set) - ft_debut(s1, set);
	if (nb <= 0)
		dest = ft_jtemalloc(nb);
	else
	{
		dest = ft_jtemalloc(nb);
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (++i < nb)
			dest[i] = s1[ft_debut(s1, set) + i];
		dest[i] = '\0';
	}
	return (dest);
}
