/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:54 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/12 16:56:40 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		proto_place(char **tetri, char **map, int t, int my, int mx, int m)
{
	int size;
	int tmp;

	tmp = 0;
	size = ft_strlen(map[0]);
	if (tetri[t] == NULL)
		return (1);
	if (ft_place_OK(tetri[t], map, my, mx) == 4 && my < size)
	{
		ft_cpy(tetri[t], map, my, mx);
		return((proto_place(tetri, map, t + 1, 0, 0, m)));
	}
	else if (ft_place_OK(tetri[t], map, my, mx) != 4 && my == size && m < 400)
	{
		while (ft_deplacetetri_ok_x(map, t - 1) == 0 && ft_deplacetetri_ok_y(map, t - 1) == 0)
		{
			ft_removetetri(map, t-1);
			t--;
		}
		if (ft_deplacetetri_ok_y(map, t - 1) == 1 && ft_deplacetetri_ok_x(map, t - 1) == 0)
				ft_deplacetetri_y(map, t - 1);
		else if (ft_deplacetetri_ok_x(map, t - 1) == 1)
			ft_deplacetetri(map, t - 1);
		m++;
		return (proto_place(tetri, map, t, 0, 0, m));
	}
	else if (map[my] == NULL)
		return (0);
	else
	{
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		return (proto_place(tetri, map, t, my, mx, m));
	}
	return (0);
}
