/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:59:50 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 16:31:41 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_setalpha(char **s)
{
	int y;
	int i;
	int lettre;

	y = 0;
	i = 0;
	lettre = 30;
	while (s[y] != 0)
	{
		while (s[y][i] != '\0')
		{
			if (s[y][i] == '#')
				s[y][i] = '#' + lettre;
			i++;
		}
		y++;
		lettre++;
		i = 0;
	}
}
