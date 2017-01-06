/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangetetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meassas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:55:01 by meassas           #+#    #+#             */
/*   Updated: 2017/01/06 16:55:07 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_xblanc(char *s)
{
	int i;

	i = 0;
	while (s[i] && i < 4)
	{
		if (s[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_yblanc(char *s)
{
	int i;

	i = 0;
	if (s[0] == '.')
		i++;
	if (s[5] == '.')
		i++;
	if (s[10] == '.')
		i++;
	if (s[15] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

void	ft_swaptetri(char *tetri, int v)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			tetri[i] = '.';
			tetri[i - v] = '#';
		}
		i++;
	}
}

void	ft_rangetetri(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i] != 0)
	{
		while (ft_xblanc(tetri[i]) == 1)
			ft_swaptetri(tetri[i], 5);
		while (ft_yblanc(tetri[i]) == 1)
			ft_swaptetri(tetri[i], 1);
		i++;
	}
}
