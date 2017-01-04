/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/04 20:05:36 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	ft_place_OK(char *tetri, char **map, int my, int mx)
{
	int_list	*t;
	int res;

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
		{
			t->y++;
			t->x = 0;
		}
		else
			t->x++;
		t->i++;
	}
	free (t);
	return (res);
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

int		placetetri(char **tetri, char **map, int_list *pos)
{
	int_list	*postmp;

	postmp = NULL;
	postmp = set_int(postmp);
	if (tetri[pos->i] == NULL)
		return(1);
	while (ft_place_OK(tetri[pos->i], map, pos->y, pos->x) != 4)
	{
		pos->x++;
		if (map[pos->y] == NULL)
		{
			if (solveur(tetri, map, pos, postmp) == 0)
			{
				ft_set_int(pos, 0);
				return (0);
			}
		}
		if (map[pos->y][pos->x] == '\0')
		{
			ft_set_int(pos, 1);
		}
	}
	ft_cpy(tetri[pos->i], map, pos->y, pos->x);
	ft_set_int(pos, 2);
	return (placetetri(tetri, map, pos));
}

int	solveur(char **tetri, char**map, int_list *pos, int_list *postmp)
{
	(void)postmp;
	if (ft_deplacebloc_ok(tetri[pos->i - 1], map, pos->i - 1, 1) == 1)
	{
		ft_deplacebloctetri(tetri[pos->i - 1], map, pos->i - 1, 1);
		ft_set_int(pos, 0);
	}
	else
	{
		while (ft_deplacebloc_ok(tetri[pos->i - 1], map, pos->i - 1, 1) == 0)
		{
			ft_removetetri(map, pos->i - 1);
			pos->i--;
		}
		if (pos->i < 0 || ft_deplacebloc_ok(tetri[pos->i], map, pos->i - 1, 1) == -1)
			return (0);
		ft_deplacebloctetri(tetri[pos->i - 1], map, pos->i - 1, 1);
		ft_set_int(pos, 0);
	}
	return (1);
}

int_list	*ft_set_int(int_list *pos, int b)
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
	return (pos);
}
