/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:33:00 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/04 15:56:31 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	j;

	j = 0;
	s1 = (char*)s;
	i = (size_t)start;
	if (!(s))
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[i] && j < len)
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}

size_t		ft_strlen(const char *s)
{
	size_t			len;
	unsigned char	*str;

	str = (unsigned char*)s;
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void		ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar(s[i++]);
}

void		ft_putendl(char const *s)
{
	char	*s1;

	s1 = (char*)s;
	if (!s)
		return ;
	if (*s)
	{
		ft_putstr((char*)s1++);
		ft_putchar('\n');
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
