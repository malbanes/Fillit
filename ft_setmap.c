/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:15:14 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/04 17:09:42 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	size_t		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
			return (NULL);
	while (i < size)
		map[i++] = ft_resetmap(size);
	map[i] = NULL;
	return (map);
}

char	**ft_map_plus_un(char **map, int tmp)
{
	free (map);
	map = ft_setmap(tmp);
	return (map);
}

void	ft_affichage(char **map)
{
	int	i;
	
	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
//	free (map);
}
/*int		main(int ac, char **av)
{
	int	i;
	char	**map;

	i = 0;
	map = ft_setmap(atoi(av[1]));
	while (map[i] != 0)
	{
		printf("%s\n", (map[i]));
		i++;
	}
	return (0);
}*/
