/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:21:37 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 18:49:29 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_TETRI_SIZE 545

typedef struct	s_map
{
	char		*content;
	int			nb_tetri;
}				t_map;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetri
{
	t_coord		t[4];
	int			order;
	int			last;
	int			put;
}				t_tetri;

typedef struct	s_res
{
	char		**smap;
	int			size;
}				t_res;

void			*ft_parse_file(int fd, t_map *map);
void			*ft_error(void);
void			*ft_error_map(t_map *map);
void			*ft_create_list(t_map *map);
void			*ft_solve(t_tetri *tab, int min_size);
int				ft_check_and_fill(t_res *res, t_tetri *tab, int i, int j);
void			ft_remove_tetri(t_res *res, t_tetri *tab);
void			ft_print_res(char **smap);
void			ft_delmap(t_res **res);

#endif
