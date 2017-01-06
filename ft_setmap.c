/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:37 by meassas           #+#    #+#             */
/*   Updated: 2017/01/06 16:55:51 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_resetmap(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_setmap(size_t size)
{
	char	**map;
	size_t	i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
		map[i++] = ft_resetmap(size);
	map[i] = NULL;
	return (map);
}

char	**ft_realloc(char **map, int tmp)
{
	free(map);
	map = ft_setmap(tmp);
	return (map);
}

void	ft_affichage(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
}
