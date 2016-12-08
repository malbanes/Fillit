/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:19:05 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/08 14:48:38 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_deplacetetri(char **map, char t)
{
	int x;
	int y;

	x = ft_strlen(map[0]) - 1;
	y = x;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (map[y][x] == t)
			{
				if (map[y][x + 1] == '.')
				{
					map[y][x] = '.';
					map[y][x + 1] = t;
				}
				else if (map[y][x] == t && map[y][x + 1] != '.')
					return (0);
			}
			x--;
		}
		x = ft_strlen(map[0]) - 1;
		y--;
	}
	return (1);
}

int		ft_removetetri(char **map, int tetri)
{
	char	t;
	int	x;
	int y;
	
	x = 0;
	y = 0;
	t = 65 + tetri;
	if (ft_deplacetetri(map, t) == 0)
	{
		while (map[y] != NULL)
		{
			while (map[y][x] != '\0')
			{
				if (map[y][x] == t)
					map[y][x] = '.';
				x++;
			}
			x = 0;
			y++;
		}
		return (0);
	}
	else
		return (1);
}

/*int		main()
{
	int i;
	char	t1[21] = "AA..\nAA..\n....\n....\n\n";
	char	t2[21] = "B...\nB...\nB...\nB...\n\n";
	char **map;

	i = 0;
	map = ft_setmap(5);
	ft_cpy(t1, map, 0, 0);
	ft_cpy(t2, map, 0, 2);
	ft_putnbr(ft_removetetri(map, 1));
	ft_putnbr(ft_removetetri(map, 0));
	while (map[i] != 0)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}*/
