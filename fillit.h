/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:38:41 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/04 20:03:24 by malbanes         ###   ########.fr       */
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

int_list	*ft_set_int(int_list *pos, int b);
int		solveur(char **tetri, char **map, int_list *pos, int_list *postmp);
void	ft_putchar(char c);
char	*ft_strsub(char const *s, unsigned int strart, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_affichage(char **map);
char	**ft_map_plus_un(char **map, int tmp);
int		placetetri(char **tetri, char **map, int_list *pos);
int		ft_deplacebloc_ok(char *tetri, char **map, int t, int one);
int		ft_placebloc_OK(char *tetri, char **map, int my, int mx, int let);
int		ft_deplacebloctetri(char *tetri, char **map, int t, int one);
void	*set_int(int_list *t);
int		ft_place_OK(char *tetri, char **map, int my, int mx);
void	ft_cpy(char *tetri, char **map, int my, int mx);
char	**ft_placeTetri(char **tetri, char **map, int t);
void	ft_setalpha(char **s);
void	*ft_resetmap(size_t size);
char	**ft_setmap(size_t size);
int		cntTetri(char *s, char c);
char	**ft_splitetri(char *s, char c);
int		ft_xblanc(char *s);
int		ft_yblanc(char *s);
void	ft_swaptetri(char *tetri, int v);
void	ft_rangetetri(char **tetri);
int		ft_sqrtSup(int nb);
int		ft_deplacetetri(char **map, int tetri);
void	ft_removetetri(char **map, int tetri);
int		check_line(char *s);
int		ft_tetri_linker(char *s);
int		ft_tetri_isvalid(char *s);
#endif
