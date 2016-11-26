

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 546// 21 Char * 26 Tetrimax

int		cntTetri(char *s, char c);

int		main()
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];

	fd = open("tetritest.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	printf("%s",  buf);
	if (close(fd) == -1)
	{
		printf("read FAILED");
		return (1);
	}
		printf("%d Tetriminos", cntTetri(buf, '\n'));
	return (0);
}
