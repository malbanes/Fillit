/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:57:38 by meassas           #+#    #+#             */
/*   Updated: 2017/01/06 16:57:55 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 546

char		*read_from_fd(char *av)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	buf = ft_strnew(BUF_SIZE);
	ret = read(fd, buf, BUF_SIZE + 1);
	buf[ret] = '\0';
	if (ret > 545 || ret < 19 || (ret + 1) % 21 != 0)
	{
		free(buf);
		ft_putendl("error");
		exit(0);
	}
	if (close(fd) == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	return (buf);
}

void		parse(int ac, char *buf)
{
	char	**tabtetri;
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putendl("usage : fillit target_file");
		exit(0);
	}
	tabtetri = ft_splitetri(buf, '\n');
	while (tabtetri[i])
	{
		if (ft_tetri_isvalid(tabtetri[i]) == 0)
		{
			ft_putendl("error");
			exit(0);
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	int			nbtetri;
	char		**tabtetri;
	char		*buf;
	char		**map;
	t_list		*pos;

	pos = NULL;
	pos = set_int(pos);
	buf = read_from_fd(av[1]);
	parse(ac, buf);
	nbtetri = cntetri(buf, '\n');
	tabtetri = ft_splitetri(buf, '\n');
	ft_rangetetri(tabtetri);
	ft_setalpha(tabtetri);
	map = ft_setmap(ft_sqrtsup(nbtetri * 4));
	nbtetri = ft_sqrtsup(nbtetri * 4);
	while (placetetri(tabtetri, map, pos) != 1)
		map = ft_realloc(map, nbtetri++);
	free(buf);
	free(pos);
	ft_affichage(map);
	free(map);
	return (0);
}
