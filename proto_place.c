/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:54 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/10 14:45:25 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		proto_place(char **tetri, char **map, int t, int my, int mx)
{
	//int my;
	//int mx;
	int size;
	int tmp;

	tmp = 0;
	ft_putstr("apl fct\n");
	size = ft_strlen(map[0]);
	if (tetri[t] == NULL)
		return (1);
		//exit(0);
	if (ft_place_OK(tetri[t], map, my, mx) == 4 && my < size)
	{
		ft_cpy(tetri[t], map, my, mx);
		tmp = 0;
		while (map[tmp])
		{
			ft_putendl(map[tmp]);
			tmp++;
		}
		ft_putstr("cpy ok\n");
		ft_putnbr(mx);
		ft_putchar('\n');
			ft_putnbr(my);
		ft_putchar('\n');
		//exit(0);
		//return (1);
		return((proto_place(tetri, map, t + 1, my, mx)));
	}
	else if (ft_place_OK(tetri[t], map, my, mx) != 4 && my == size)
	//else if (proto_place(tetri, map, t, my, mx) == 0)
	{
		ft_putstr("fail tetri+1\n");
		if (ft_deplacetetri(map, t) == 0)
		{
			ft_removetetri(map, t);
			ft_putstr("remove ok\n");
			return (proto_place(tetri, map, t, my, mx + 1));
		}
		else
		{
			ft_putendl("deplace ok");
			ft_deplacetetri(map, t);
			return (ft_deplacetetri(map, t++));
			//return (proto_place(tetri, map, t  1, my, mx + 1));
		}
	}
	else
	{
		ft_putnbr(mx);
		ft_putchar('\n');
			ft_putnbr(my);
		ft_putchar('\n');
		ft_putendl("else");
		//mx++;
		if (map[my][mx] == '\0')
		{
			my += 1;
			mx = -1;
			ft_putendl("bsh");
			if (ft_deplacetetri(map, t--) == 1)
			{
					ft_removetetri(map, t);
					ft_putendl("bsh2");
				my += 1;
				mx = -1;
			}
			//my += 1;
			//mx = -1;
			ft_putnbr(mx);
		ft_putchar('\n');
			ft_putnbr(my);
			ft_putchar('\n');
		}
		if (my == size + 1)
			my--;
		if (map[my] == NULL)
		{
			ft_putendl("null");
			//my--;
			//exit(0);
			return (0);
		}
		return (proto_place(tetri, map, t, my, mx + 1));
	}
	return (0);
}
