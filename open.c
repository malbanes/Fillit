

#include "fillit.h"
#include "libft.h"

#define BUF_SIZE 546// 21 Char * 26 Tetrimax

char	*read_from_fd(char *av)
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
		ft_putendl("error");
		exit (0);
	}
	if (close(fd) == -1)
	{
		ft_putendl("Read Failed");
		exit (0);
	}
	return (buf);
}

void	fillit(char *buf)
{
	char **tabtetri;
	int cur;

	cur = 0;
	tabtetri = ft_splitetri(buf, '\n');
	while (tabtetri[cur])
	{
		if (ft_tetri_isvalid(tabtetri[cur]) == 0)
		{
			ft_putendl("error");
			exit (0);
		}
		cur++;
	}
}

int		main(int ac, char **av)
{
	int nbtetri;
	char **tabtetri;
	int tmp;
	char *buf;
	char **map;
	int_list	*pos;

	pos = NULL;
	pos = set_int(pos);
	buf = read_from_fd(av[1]);
	if (ac != 2)
	{
		ft_putendl("usage : fillit target_file");
		exit (0);
	}
	tmp = 0;
	fillit(buf);
	nbtetri = cntTetri(buf, '\n');
	tabtetri = ft_splitetri(buf, '\n');
	ft_rangetetri(tabtetri);
	ft_setalpha(tabtetri);
	map = ft_setmap(ft_sqrtSup(nbtetri * 4));
//	map = ft_setmap(5);
	tmp = ft_sqrtSup(nbtetri * 4);
	while (placetetri(tabtetri, map, pos) != 1)
	{
	//	free (map);
	//	free (pos);
		//pos = set_int(pos);
		map = ft_map_plus_un(map, tmp++);
	}
	free (pos);
	ft_affichage(map);
	free (map);
	return (0);
}
