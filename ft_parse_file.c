/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:25:23 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/20 15:44:16 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_check_tetri(t_map *map, int i)
{
	int j;
	int newline;
	int hash_adj;

	j = i;
	newline = j / 21;
	hash_adj = 0;
	if ((i - newline) % 20 > 0)
		if (map->content[i - 1] == '#')
			hash_adj++;
	if ((i - newline) % 20 > 4)
		if (map->content[i - 5] == '#')
			hash_adj++;
	if (map->content[i + 1] == '#')
		hash_adj++;
	if ((i - newline) % 20 < 14)
		if (map->content[i + 5] == '#')
			hash_adj++;
	return (hash_adj);
}

static void		*ft_check_error_shape(t_map *map)
{
	int i;
	int valid_tetri;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i] == '#')
		{
			valid_tetri = 0;
			while (map->content[i + 1] && !(map->content[i] == '\n' &&
				map->content[i - 1] == '\n'))
			{
				if (map->content[i] == '#')
					valid_tetri += ft_check_tetri(map, i);
				i++;
			}
			if (valid_tetri != 6 && valid_tetri != 8)
				return (ft_error_map(map));
		}
		i++;
	}
	return ((t_res *)ft_create_list(map));
}

static void		*ft_check_newline(t_map *map)
{
	int	i;
	int j;
	int curr_tetri;

	i = 0;
	curr_tetri = 0;
	while (map->content[i])
	{
		if (map->content[i] == '\n')
		{
			j = i - 4;
			while (j < i - 1)
			{
				if (map->content[j] == '\n')
					return (ft_error_map(map));
				j++;
			}
			if (map->content[j] == '\n' && (i - curr_tetri) % 20 != 0)
				return (ft_error_map(map));
			else if (map->content[j] == '\n' && (i - curr_tetri) % 20 == 0)
				curr_tetri++;
		}
		i++;
	}
	return ((t_res *)ft_check_error_shape(map));
}

static void		*ft_check_error_nbchars(t_map *map)
{
	int i;
	int	c_hashtag;
	int c_dot;
	int	c_newline;

	i = 0;
	c_hashtag = 0;
	c_dot = 0;
	c_newline = 0;
	while (map->content[i])
	{
		if (map->content[i] == '#')
			c_hashtag++;
		else if (map->content[i] == '.')
			c_dot++;
		else if (map->content[i] == '\n' && i < 4)
			return (ft_error_map(map));
		else if (map->content[i] == '\n')
			c_newline++;
		i++;
	}
	if ((c_hashtag / map->nb_tetri != 4) || (c_dot / map->nb_tetri != 12)
		|| ((c_newline - (map->nb_tetri - 1)) / map->nb_tetri != 4))
		return (ft_error_map(map));
	return ((t_tetri *)ft_check_newline(map));
}

void			*ft_parse_file(int fd, t_map *map)
{
	int		rd;
	int		i;
	t_res	*res;
	char	buf[MAX_TETRI_SIZE + 1];

	i = 0;
	while ((rd = read(fd, &buf, 1)) > 0)
	{
		map->content = ((!(map->content)) ? ft_strdup(buf) :
				ft_strfreejoin(map->content, buf, 1));
		if (map->content[i] != '.' && map->content[i] != '\n' &&
			map->content[i] != '#')
			return (ft_error_map(map));
		if (map->content[i] == '\n' && map->content[i - 1] == '\n')
			map->nb_tetri++;
		i++;
	}
	if (map->content != NULL && ((i - (map->nb_tetri - 1)) % 20) == 0 &&
		rd == 0 && i <= MAX_TETRI_SIZE)
	{
		res = (t_res *)ft_check_error_nbchars(map);
		free(map->content);
		return (res);
	}
	return (ft_error_map(map));
}
