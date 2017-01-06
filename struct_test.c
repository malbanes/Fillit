/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:09:33 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 16:58:39 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		*set_int(t_list *t)
{
	t = malloc(sizeof(t_list));
	t->i = 0;
	t->x = 0;
	t->y = 0;
	t->one = 0;
	return (t);
}

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = 0;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
