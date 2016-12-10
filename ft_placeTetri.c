/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/09 15:24:39 by malbanes         ###   ########.fr       */
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

/*char	**ft_placeTetri(char **tetri, char **map, int t)
{
	int	my;
	int	mx;
	int	size;

	my = 0;
	mx = 0;
	size = ft_strlen(map[0]);
	if (ft_place_OK(tetri[t], map, my, mx) == 4)
	{
		ft_cpy(tetri[t], map, my, mx);
		return (ft_placeTetri(tetri, map, t++));
	}
	else
	{
		if (ft_placeTetri(tetri, map, t++) == NULL)
		{
			if (ft_deplacetetri(map, t) == 1)
				return (ft_placeTetri(tetri, map, t++));
			else
			{
				ft_removetetri(map, t);
				ft_deplacetetri(map, t - 1);
				return (ft_placeTetri(tetri, map, t));
			}
		}
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		if (my == size)
		{
			return (NULL);
		}
		if (t > size)
			return (map);
	}
	return (map);
} */
