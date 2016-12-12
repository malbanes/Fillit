/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:19:05 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/12 20:13:03 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_deplacetetri_ok_x(char **map, int tetri)
{
	char t;
	int x;
	int y;

	x = ft_strlen(map[0]) - 1;
	y = x;
	t = 65 + tetri;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (map[y][x] == t)
			{
				if (map[y][x + 1] != '.' && map[y][x + 1] != t)
					return (0);
			}
			x--;
		}
		x = ft_strlen(map[0]) - 1;
		y--;
	}
	return (1);
}

int		ft_deplacebloctetri(char **tetri, char **map, int t, int one)
{
	int y;
	int x;
	int size;

	size = ft_strlen(map[0]) - 1;
	y = 0;
	x = 0;
	while (y < size)
	{
		while (x <= size)
		{
			if (map[y][x] == t + 65 && one == 1)
			{
				ft_removetetri(map, t);
				y = y + 1;
				x = 0;
				one = 0;
			}
			if (ft_place_OK(tetri[t], map, y, x) == 4 && one == 0)
			{
				ft_cpy(tetri[t], map, y, x);
				one = 3;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_deplacetetri_y(char **map, int tetri)
{
	char t;
	int y;
	int x;

	x = ft_strlen(map[0]) - 1;
	y = x;
	t = 65 + tetri;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (map[y][x] == t)
			{
				if (map[y + 1][x] == '.')
				{
					map[y + 1][x] = t;
					map[y][x] = '.';
				}
				else if (map[y][x] == t && map[y + 1][x] != '.')
					return (0);
			}
			x--;
		}
		x = ft_strlen(map[0]) - 1;
		y--;
	}
	return (1);
}

int		ft_deplacetetri(char **map, int tetri)
{
	char	t;
	int x;
	int y;

	x = ft_strlen(map[0]) - 1;
	y = x;
	t = 65 + tetri;
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

void	ft_removetetri(char **map, int tetri)
{
	char	t;
	int	x;
	int y;
	
	x = 0;
	y = 0;
	t = 65 + tetri;
//	if (ft_deplacetetri(map, t) == 0)
//	{
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

//	}
//	else
//		return (1);
}
/*
int		main()
{
	int i;
	char	t1[21] = "AA..\nAA..\n....\n....\n\n";
	char	t2[21] = "B...\nBBB.\n....\n....\n\n";
	char **map;

	i = 0;
	map = ft_setmap(5);
	ft_cpy(t1, map, 3, 3);
	ft_cpy(t2, map, 0, 2);
	if (ft_deplacetetri_ok_y(map, 1) == 1)
		ft_deplacetetri_y(map, 1);
	if (ft_deplacetetri_ok_y(map, 1) == 1)
		ft_deplacetetri_y(map, 1);
//	ft_putnbr(ft_removetetri(map, 0));
	{
		while (map[i] != 0)
		{
			printf("%s\n", map[i]);
			i++;
		}
}
	return (0);
}*/
