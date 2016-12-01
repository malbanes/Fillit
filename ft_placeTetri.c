/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/01 16:08:07 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_place_OK(char *tetri, char **map, int my, int mx)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -1;
	y = 0;
	while (tetri[i])
	{
		x++;
		if (tetri[i] == '\n')
		{
			y++;
			x = -1;
		}
		if (tetri[i] != '.' && tetri[i] != '\n')
			if (map[my + y][mx + x] != '.')
				return (0);
		i++;
	}
	return (1);
}

void	ft_cpy(char *tetri, char **map, int my, int mx)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -1;
	y = 0;
	while (tetri[i])
	{
		x++;
		if (tetri[i] == '\n')
		{
			y++;
			x = -1;
		}
		if (tetri[i] != '.' && tetri[i] != '\n')
			map[my + y][mx + x] = tetri[i];
		i++;
	}
}

char	**ft_placeTetri(char **tetri, char **map)
{
	int	t;
	int	my;
	int	mx;
	int test;

	test = 0;
	t = 0;
	my = 0;
	mx = 0;
	while (t <= 2)
	{
		printf("%d\n", ft_place_OK(tetri[t], map, my, mx));
		if (ft_place_OK(tetri[t], map, my, mx) == 1)
		{
			ft_cpy(tetri[t], map, my, mx);
			t++;
			test = 0;
			while (map[test] != 0)
			{
				printf("%s\n", map[test]);
				test++;
			}
		}
		else
		{
			mx++;
			if (map[my][mx] == '\0')
			{
				my++;
				mx = 0;
			}
			if (map[my] == 0)
			{
				printf("pas de place");
				return (0);
//			free && realloc + 1
			}
		}
	}
	return (map);
}
