/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:38:41 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/08 18:59:41 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct		int_list
{
	int		i;
	int		x;
	int		y;
}					int_list;

void	*set_int(int_list *t);
int		ft_place_OK(char *tetri, char **map, int my, int mx);
void	ft_cpy(char *tetri, char **map, int my, int mx);
char	**ft_placeTetri(char **tetri, char **map, int t);
void	ft_setalpha(char **s);
void	*ft_memallocMap(size_t size);
char	**ft_setmap(size_t size);
int		cntTetri(char *s, char c);
char	**ft_splitetri(char *s, char c);
int		ft_xblanc(char *s);
int		ft_yblanc(char *s);
void	ft_swaptetri(char *tetri, int v);
void	ft_rangetetri(char **tetri);
int		ft_sqrtSup(int nb);
int		ft_deplacetetri(char **map, int tetri);
int		ft_removetetri(char **map, int tetri);
#endif