

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 550// 21 Char * 26 Tetrimax

char	**ft_splitetri(char *s, char c);
int		cntTetri(char *s, char c);
void	ft_putstr(char *s);
void	ft_setalpha(char **s);
char	**ft_setmap(size_t size);
char	**ft_placeTetri(char **tetri, char **map);
void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char	**tabtetri;
	int		y;
	char	**map;
	char	**map2;

	if (ac > 2)
	{
		ft_putstr("<ERROR> Too many arguments");
		return (0);
	}
	y = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	if (ret > 546) //nb de char max pour 26 tetriminos
	{
		ft_putstr("<ERROR> Too many characters\nCheck your entrance file");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("read FAILED");
		return (1);
	}
	tabtetri = ft_splitetri(buf, '\n');
//	free(buf);
	ft_setalpha(tabtetri);
	map = ft_setmap(5);
	map2 = (ft_placeTetri(tabtetri, map));
	while (map[y] != 0)
	{
		ft_putstr(map[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}
