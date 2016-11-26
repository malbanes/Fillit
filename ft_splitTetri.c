#include <stdlib.h>


static int		cntTetri(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] || (s[i] != '\n' && s[i] != '.' && s[i] != '#'))
	{
		if (s[i] == c && (s[i + 1] == c))
			j++;
		i++;
	}
	return (j);
}

/*char		**ft_strsplit(char *s, char c)
{
	int		i;
	int		y;
	char	**split;
	int		end;

	i = 0;
	y = 0;
	end = 0;
	if (!(split = (char**)malloc(sizeof(char*) * (cntTetri(s, c)) + 1))
		|| (!s))
		return (NULL);
	while (y < cntTetri(s, c) && s[i]) //s[i] faciltatif
	{
		if (s[i] 
	}
}*/
