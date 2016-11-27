

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 546// 21 Char * 26 Tetrimax

char	**ft_splitetri(char *s, char c);
int		cntTetri(char *s, char c);
void	ft_putstr(char *s);
void	ft_setalpha(char **s);

int		main()
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char	**tabtetri;
	int		y;

	y = 0;
	fd = open("tetritest.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		printf("read FAILED");
		return (1);
	}
	tabtetri = ft_splitetri(buf, '\n');
//	free(buf);
	ft_setalpha(tabtetri);
	while (tabtetri[y] != 0)
	{
		ft_putstr(tabtetri[y]);
		ft_putstr("Tetri suivant\n");
		y++;
	}
	return (0);
}
