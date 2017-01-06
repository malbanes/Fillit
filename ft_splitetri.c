/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:56:07 by meassas           #+#    #+#             */
/*   Updated: 2017/01/06 16:56:11 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			cntetri(char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] == c))
			j++;
		else if (s[i] == c && s[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}

char		**ft_splitetri(char *s, char c)
{
	int		i;
	int		y;
	char	**split;

	i = 0;
	y = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (cntetri(s, c)) + 1))
		|| (!s))
		return (NULL);
	while (y < cntetri(s, c) && s[i])
	{
		split[y++] = ft_strsub(s, i, 21);
		i += 21;
	}
	split[y] = 0;
	return (split);
}
