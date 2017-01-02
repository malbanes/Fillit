/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:40:14 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/02 13:53:16 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	*ft_memallocmap(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_setmap(size_t size)
{
	char	**map;
	size_t	i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
		map[i++] = ft_memallocmap(size);
	map[i] = NULL;
	return (map);
}
