/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeTetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:52 by malbanes          #+#    #+#             */
/*   Updated: 2016/11/30 15:56:36 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_place_OK(char *tetri, char **map, int my, int mx)
{
	int t;
	int y;
	int x;
	int i;

	y = 0;
	x = 0;
	t = 1;
	i = 0;
	while (tetri[i] < 'A' && tetri[i] > 'Z' && tetri[i] != '\0')
		i++;
	while (map[y][x] && tetri[t])
	{
		if (tetri[t + i] >= 'A' && tetri[t + i] <= 'Z')
		{
			y = my + (t / 5);
			x = mx + ((t % 5) / 2);
		}
		if (map[y][x] != '.' || map[y][x] == '\0' || map[y] == 0 )
			return (0);
		t++;
	}
	return (1);
}

void	ft_cpy(char *tetri, char **map, int my, int mx)
{
	int t;
	int y;
	int x;
	int i;

	i = 0;
	t = 1;
	y = 0;
	x = 0;
	while (tetri[i] < 'A' && tetri[i] > 'Z' && tetri[i] != '\0')
		i++;
	i--;
	while (map[y][x] && tetri[t])
	{
		if (tetri[t + i] >= 'A' && tetri[t + i] <= 'Z')
		{
		y = my + (t / 5);
		x = mx + ((t % 5) / 2);
		map[y][x] = tetri[t + i];
		}
		t++;
	}
}

char	**ft_placeTetri(char **tetri, char **map)
{
	int	t;
	int	my;
	int	mx;

	t = 0;
	my = 0;
	mx = 0;
	while (t <= 2)
	{
		if (ft_place_OK(tetri[t], map, my, mx) == 1)
		{
			ft_cpy(tetri[t], map, my, mx);
			t++;
		}
		else
		{
			mx++;
			if (map[my][mx] == '\0')
			{
				my++;
				mx = 0;
			}
		}
	}
	return (map);
}









