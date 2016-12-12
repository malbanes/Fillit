/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:54 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/10 18:17:32 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		proto_place2(char **tetri, char **map, int t, int my, int mx)
{
	int size;

	size = ft_strlen(map[0]);
	if (tetri[t] == NULL)
		return (1);
	ft_putstr("aplftc\n");
	if (ft_place_OK(tetri[t], map, my, mx) == 4 && my < size)
	{
		ft_cpy(tetri[t], map, my, mx);
		return((proto_place2(tetri, map, t + 1, 0, 0)));
	}
	else if (ft_place_OK(tetri[t], map, my, mx) != 4 && my == size)
	{
		while (ft_deplacetetri(map, t - 1) == 0)
		{
			ft_removetetri(map, t - 1);
			t--;
		}
		ft_deplacetetri(map, t - 1);
		return (proto_place2(tetri, map, t, 0, 0));
	}
	else
	{
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		if (map[my] == NULL)
			return (1);
		return (proto_place2(tetri, map, t, my, mx));
	}
	return (0);
}
