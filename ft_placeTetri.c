/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placetetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:51:47 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 17:00:15 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_place_ok(char *tetri, char **map, int my, int mx)
{
	t_list		*t;
	int			res;

	t = NULL;
	res = 0;
	t = set_int(t);
	while (tetri[t->i] != '\0')
	{
		if (tetri[t->i] >= 'A' && tetri[t->i] <= 'Z')
			if ((my + t->y) >= (int)ft_strlen(map[0]))
				return (0);
		if (tetri[t->i] >= 'A' && tetri[t->i] <= 'Z')
		{
			if (map[my + t->y][mx + t->x] == '.')
				res++;
			t->x++;
		}
		else if (tetri[t->i] == '\n' && tetri[t->i + 1] != '\n')
			ft_set_int(t, 1);
		else
			t->x++;
		t->i++;
	}
	free(t);
	return (res);
}

void		ft_cpy(char *tetri, char **map, int my, int mx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
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

int			placetetri(char **tetri, char **map, t_list *pos)
{
	t_list	*pos2;

	pos2 = NULL;
	pos2 = set_int(pos2);
	if (tetri[pos->i] == NULL)
		return (1);
	while (ft_place_ok(tetri[pos->i], map, pos->y, pos->x) != 4)
	{
		pos->x++;
		if (map[pos->y] == NULL)
		{
			if (solveur(tetri, map, pos, pos2) == 0)
			{
				ft_set_int(pos, 0);
				return (0);
			}
		}
		if (map[pos->y][pos->x] == '\0')
			ft_set_int(pos, 1);
	}
	ft_cpy(tetri[pos->i], map, pos->y, pos->x);
	ft_set_int(pos, 2);
	free(pos2);
	return (placetetri(tetri, map, pos));
}

int			solveur(char **tetri, char **map, t_list *pos, t_list *postmp)
{
	postmp->i = pos->i - 1;
	if (ft_deplacebloc_ok(tetri[pos->i - 1], map, postmp, 1) == 1)
	{
		ft_deplacebloctetri(tetri[pos->i - 1], map, postmp, 1);
		ft_set_int(pos, 0);
	}
	else
	{
		while (ft_deplacebloc_ok(tetri[pos->i - 1], map, postmp, 1) == 0)
		{
			ft_removetetri(map, pos->i - 1);
			pos->i--;
			postmp->i = pos->i - 1;
		}
		if (pos->i < 0 ||
				ft_deplacebloc_ok(tetri[pos->i], map, postmp, 1) == -1)
			return (0);
		ft_deplacebloctetri(tetri[pos->i - 1], map, postmp, 1);
		ft_set_int(pos, 0);
	}
	return (1);
}

t_list		*ft_set_int(t_list *pos, int b)
{
	if (b == 0)
	{
		pos->y = 0;
		pos->x = 0;
	}
	if (b == 1)
	{
		pos->y++;
		pos->x = 0;
	}
	if (b == 2)
	{
		pos->i++;
		pos->y = 0;
		pos->x = 0;
	}
	if (b == 10)
	{
		pos->y++;
		pos->x = -1;
	}
	return (pos);
}
