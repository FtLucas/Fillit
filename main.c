/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:06:59 by luwargni          #+#    #+#             */
/*   Updated: 2019/01/19 18:58:55 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int				main(int ac, char **av)
{
	int		fd;
	t_res	*res;
	t_map	map;

	fd = 0;
	map.nb_tetri = 1;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_error();
			return (-1);
		}
		if ((res = ft_parse_file(fd, &map)) == NULL)
			return (-1);
		ft_print_res(res->smap);
		ft_delmap(&res);
		close(fd);
	}
	else
	{
		ft_putstr("usage : ./fillit source_file\n");
		return (-1);
	}
	return (0);
}
