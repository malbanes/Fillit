/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplacetetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:50:46 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 16:49:13 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_placebloc_ok(char *tetri, char **map, t_list *pos2)
{
	t_list		*t;
	int			res;

	t = NULL;
	res = 0;
	t = set_int(t);
	while (tetri[t->i] != '\0')
	{
		if (tetri[t->i] == pos2->i + 65)
			if ((pos2->y + t->y) >= (int)ft_strlen(map[0]))
				return (0);
		if (tetri[t->i] == pos2->i + 65)
		{
			if (map[pos2->y + t->y][pos2->x + t->x] == '.' ||
					map[pos2->y + t->y][pos2->x + t->x] == pos2->i + 65)
				res++;
		}
		else if (tetri[t->i] == '\n' && tetri[t->i + 1] != '\n')
			ft_set_int(t, 10);
		t->i++;
		t->x++;
	}
	free(t);
	return (res);
}

int		ft_deplacebloc_ok(char *tetri, char **map, t_list *pos2, int one)
{
	int		i;

	i = 0;
	ft_set_int(pos2, 0);
	if (pos2->i == -1)
		return (-1);
	while (tetri[i] && map[pos2->y][pos2->x] && tetri[i] == '.')
		i++;
	while (map[pos2->y] != NULL)
	{
		while (map[pos2->y][pos2->x] != '\0')
		{
			pos2->one = i;
			pos2->x = pos2->x - pos2->one;
			if (map[pos2->y][pos2->x + i] == (pos2->i + 65) && one == 1)
				one = 0;
			else if (ft_placebloc_ok(tetri, map, pos2) == 4 && one == 0 &&
					(one += 3))
				return (1);
			pos2->x = pos2->x + pos2->one + 1;
		}
		ft_set_int(pos2, 1);
	}
	return (0);
}

int		ft_deplacebloctetri(char *tetri, char **map, t_list *pos2, int one)
{
	int		i;

	i = 0;
	ft_set_int(pos2, 0);
	while (tetri[i] && tetri[i] == '.' && map[pos2->y][pos2->x])
		i++;
	while (map[pos2->y] != NULL)
	{
		while (map[pos2->y][pos2->x] != '\0')
		{
			if (map[pos2->y][pos2->x] == pos2->i + 65 && one == 1
					&& !(one = 0))
				ft_removetetri(map, pos2->i);
			else if (ft_place_ok(tetri, map, pos2->y, pos2->x - i) == 4
					&& one == 0)
			{
				ft_cpy(tetri, map, pos2->y, pos2->x - i);
				return (1);
			}
			pos2->x++;
		}
		ft_set_int(pos2, 1);
	}
	return (0);
}

void	ft_removetetri(char **map, int tetri)
{
	char	t;
	int		x;
	int		y;

	x = 0;
	y = 0;
	t = 65 + tetri;
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
}
