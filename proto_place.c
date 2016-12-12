/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:54 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/12 13:32:07 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		proto_place(char **tetri, char **map, int t, int my, int mx, int m)
{
	//int my;
	//int mx;
	int size;
//	int tmp;

//	tmp = 0;
//	ft_putstr("apl fct\n");
	size = ft_strlen(map[0]);
	if (tetri[t] == NULL)
		return (1);
	if (ft_place_OK(tetri[t], map, my, mx) == 4 && my < size)
	{
		ft_cpy(tetri[t], map, my, mx);
//		tmp = 0;
//		while (map[tmp])
//		{
//			ft_putendl(map[tmp]);
//			tmp++;
//		}
//		ft_putstr("cpy ok\n");
		//return (1);
		return((proto_place(tetri, map, t + 1, 0, 0, m)));
	}
	else if (ft_place_OK(tetri[t], map, my, mx) != 4 && my == size && m < 400)
	{
//		ft_putstr("fail tetri+1\n");
		while (ft_deplacetetri(map, t - 1) == 0)
		{
			ft_removetetri(map, t - 1);
			t--;
//			ft_putstr("remove ok\n");
		}
//		ft_putendl("deplace ok");
		ft_deplacetetri(map, t - 1);
		//return (ft_deplacetetri(map, t++));
		m++;
		ft_putnbr(m);
		ft_putchar('\n');
		return (proto_place(tetri, map, t, 0, 0, m));
	}
	else if (map[my] == NULL)
	{
		ft_putendl("proto place =0");
		return (0);
	}
	else
	{
//		if (map[my + 1] == NULL && map[my][mx] == '\0')
//			return (0);
		mx++;
		if (map[my][mx] == '\0')
		{
			my++;
			mx = 0;
		}
		if (my == size + 1)
			my--;
//		if (map[my] == NULL)
//		{
//			ft_putendl("null");
//			return (0);
//		}
		return (proto_place(tetri, map, t, my, mx, m));
	}
	ft_putendl("proto place =0");
	return (0);
}
