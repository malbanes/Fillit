/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_ok_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:43:46 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/07 15:11:05 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		place_ok_test(char *tetri, char **map, int my, int mx)
{
	int i;
	int x;
	int y;
	int res;

	res = 0;
	i = 0;
	y = 0;
	x = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] >= 'A' && tetri[i] <= 'Z')
			if ((my + y) >= ft_strlen(map[0]))//5 = taille de la map
				return (0);
		if(tetri[i] >= 'A' && tetri[i] <= 'Z')
		{
			if (map[my + y][mx + x] == '.')
				res ++;
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
		if (res == 4)
			return (1);
	}
	return (0);
}

/*int	main()
{
	char str[25] = "BB..\nBB..\n....\n....\n\n";
	char **map;
	int i;

	i = 0;
	map = ft_setmap(5);
	map[0][0] = 'A';
	map[0][1] = 'A';
	map[1][0] = 'A';
	map[1][1] = 'A';
	printf("%d", place_ok_test(str, map, 0, 3));
	ft_putchar('\n');
	while (map[i])
	{
	ft_putstr(map[i]);
	ft_putchar('\n');
	i++;
	}
	return (0);
}*/
