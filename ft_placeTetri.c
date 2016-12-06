/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/06 18:47:36 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		place_ok_test(char *tetri, char **map, int my, int mx);

int	ft_place_OK(char *tetri, char **map, int my, int mx)
{
	int i;
	int x;
	int y;

	i = 0;
	x = -1;
	y = 0;
	while (tetri[i] != '\0')
	{
		x++;
		if (tetri[i] == '\n' && tetri[i + 1] != '\n')
		{
			y++;
			x = -1;
		}
		if (tetri[i] != '.' && tetri[i] != '\n' && (map[my + y][mx + x] != '.' || map[my + y] == NULL))
				return (0);
		else if (tetri[i] != '.' && tetri[i] != '\n')
			map[my + y][mx + x] = 'c';
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
	y = 0;
	x = 0;
	while (tetri[i] != '\0')
	{
		if(tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			map[my + y][mx + x] = tetri[i];
			x++;
		}
		else if (tetri[i] == '\n' && tetri[i + 1] != '\n')
		{
		y++;
		x = 0;
		}
		else
			x++;
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
	while (tetri[t])
	{
//		printf("%d\n", ft_place_OK(tetri[t], map, my, mx));
		ft_putnbr(place_ok_test(tetri[t], map, my, mx));
		printf("\n");
		if (my == 5)
			exit(0);
			//myrealloc(map[my + 1][mx + 1]);
		if (place_ok_test(tetri[t], map, my, mx) == 1)
		{
			ft_cpy(tetri[t], map, my, mx);
			t++;
			my = 0;
			mx = 0;
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
			if (mx == 5)
			{
				printf("pas de place");
				return (NULL);
//			free && realloc + 1
			}
		}
	}
	return (map);
}
