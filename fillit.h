/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:38:41 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/06 17:00:44 by meassas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_fillit
{
	int		i;
	int		x;
	int		y;
	int		one;
}					t_list;

t_list				*ft_set_int(t_list *pos, int b);
char				*ft_strnew(size_t size);
int					solveur(char **tetri, char **map, t_list *pos, t_list
		*postmp);
void				ft_putchar(char c);
char				*ft_strsub(char const *s, unsigned int strart, size_t len);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_affichage(char **map);
char				**ft_realloc(char **map, int tmp);
int					placetetri(char **tetri, char **map, t_list *pos);
int					ft_deplacebloc_ok(char *tetri, char **map, t_list
		*pos2, int one);
int					ft_placebloc_ok(char *tetri, char **map, t_list *pos2);
int					ft_deplacebloctetri(char *tetri, char **map, t_list
		*pos2, int one);
void				*set_int(t_list *t);
int					ft_place_ok(char *tetri, char **map, int my, int mx);
void				ft_cpy(char *tetri, char **map, int my, int mx);
void				ft_setalpha(char **s);
void				*ft_resetmap(size_t size);
char				**ft_setmap(size_t size);
int					cntetri(char *s, char c);
char				**ft_splitetri(char *s, char c);
int					ft_xblanc(char *s);
int					ft_yblanc(char *s);
void				ft_swaptetri(char *tetri, int v);
void				ft_rangetetri(char **tetri);
int					ft_sqrtsup(int nb);
int					ft_deplacetetri(char **map, int tetri);
void				ft_removetetri(char **map, int tetri);
int					check_line(char *s);
int					ft_tetri_linker(char *s);
int					ft_tetri_isvalid(char *s);

#endif
