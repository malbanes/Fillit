/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:45:54 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/02 13:52:58 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fillit.h"
#include "libft.h"

#define BUF_SIZE 550// 21 Char * 26 Tetrimax

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char	**tabtetri;
	int		y;
	char	**map;
	int	tmp;
	int		nbtetri;

	tmp = 0;
	if (ac > 2)
	{
		ft_putstr("<ERROR> Too many arguments");
		return (0);
	}
	y = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == - 1)
	{
		ft_putstr("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	if (ret > 546 || ret < 19) //nb de char max pour 26 tetriminos
	{
		ft_putstr("<ERROR>");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("read FAILED");
		return (1);
	}
	nbtetri = cntetri(buf, '\n');
	tabtetri = ft_splitetri(buf, '\n');
//	Check tetri valides
	while (tabtetri[tmp] != 0)
	{
		if (ft_tetri_isvalid(tabtetri[tmp]) == 0)
		{
			ft_putendl("tetri invalide");
			return (0);
		}
		tmp++;
	}
	ft_rangetetri(tabtetri);
	ft_setalpha(tabtetri);
	map = ft_setmap(ft_sqrtsup(nbtetri * 4));
	if (nbtetri == 1)				//Condition, si 1 seul tetri
	{
		while (ft_place_OK(tabtetri[0], map, 0, 0) != 4)
		{
			free (map);
			nbtetri++;
			map = ft_setmap(nbtetri);
		}
		ft_cpy(tabtetri[0], map, 0, 0);
	}								// fin condition si 1 seul tetri
	else
	{
		while (placetetri(tabtetri, map, 0, 0, 0, 0) != 1)
		{
			free (map);
			nbtetri++;
			map = ft_setmap(nbtetri);
		}
	}
	y = 0;
	while (map[y] != 0)
	{
		ft_putstr(map[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}
