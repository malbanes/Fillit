/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removetetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:19:05 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 15:24:06 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_placebloc_ok(char *tetri, char **map, int_list *pos2, int_list *pos3)
{
	int res;

	res = 0;
	pos2->x = pos2->x - pos2->one;
	while (tetri[pos3->i] != '\0')
	{
		if (tetri[pos3->i] == pos2->i + 65)
			if ((pos2->y + pos3->y) >= (int)ft_strlen(map[0]))
				return (0);
		if (tetri[pos3->i] == pos2->i + 65)
		{
			if (map[pos2->y + pos3->y][pos2->x + pos3->x] == '.' ||
					map[pos2->y + pos3->y][pos2->x + pos3->x] == pos2->i + 65)
				res++;
			pos3->x++;
		}
		else if (tetri[pos3->i] == '\n' && tetri[pos3->i + 1] != '\n')
			ft_set_int(pos3, 1);
		else
			pos3->x++;
		pos3->i++;
	}
	free(pos3);
	pos2->x = pos2->x + pos2->one;
	return (res);
}

int		ft_deplacebloc_ok(char *tetri, char **map, int_list *pos, int_list *pos2)
{
	int i;
	int_list	*pos3;

	i = 0;
	pos3 = NULL;
	pos3 = set_int(pos3);
	if (pos2->i == -1)
		return (-1);
	while (tetri[i] && map[pos2->y][pos2->x] && tetri[i] == '.')
		i++;
	while (map[pos2->y] != NULL)
	{
		while (map[pos2->y][pos2->x] != '\0')
		{
			pos2->one = i;
			if (map[pos2->y][pos2->x] == pos2->i + 65 && pos->one == 1)
				pos->one = 0;
			else if (ft_placebloc_ok(tetri, map, pos2, pos3) == 4 
					&& pos->one == 0 && (pos->one += 1))
				return (1);
			pos2->x++;
		}
		ft_set_int(pos2, 1);
	}
	return (0);
}

int		ft_deplacetetri(char *tetri, char **map, int_list *pos, int_list *pos2)
{
	int i;

	i = 0;
	while (tetri[i] && tetri[i] == '.' && map[pos2->y][pos2->x])
		i++;
	while (map[pos2->y] != NULL)
	{
		while (map[pos2->y][pos2->x] != '\0')
		{
			if (map[pos2->y][pos2->x] == pos2->i + 65 && pos->one == 1 &&
					(pos->one -= 0))
				ft_removetetri(map, pos2->i);
			else if (ft_place_ok(tetri, map, pos2->y, pos2->x - i) == 4 &&
					pos->one == 0)
			{
				ft_cpy(tetri, map, pos2->y, pos2->x - i);
				pos->one = 1;
				return (1);
			}
		}
		ft_set_int(pos2, 1);
	}
	return (0);
}

void	ft_removetetri(char **map, int tetri)
{
	char	t;
	int	x;
	int y;
	
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

/*int		main()
{
	int i;
	int b;
	char	t1[21] = "AAAA\n....\n....\n....\n\n";
	char	t2[21] = "BB..\n.B..\n.B..\n....\n\n";
	//char	t3[21] = "CC..\nCC..\n....\n....\n\n";
	char **map;

	b = 0;
	i = 0;
	map = ft_setmap(4);
	ft_cpy(t1, map, 3, 0);
	//ft_cpy(t3, map, 3, 2);
	ft_cpy(t2, map, 0, 0);
	while (b < 8)
	{
		ft_putnbr(ft_deplacebloc_ok(t2, map, 1, 1));
		ft_putchar('\n');
		if (ft_deplacebloc_ok(t2, map, 1, 1) == 1)
			ft_deplacebloctetri(t2, map, 1, 1);
		i = 0;
		while (map[i] != 0)
		{
			printf("%s\n", map[i]);
			i++;
		}
		b++;
	}
	return (0);
}*/
