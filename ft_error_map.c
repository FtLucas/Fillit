/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:57:45 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 15:57:52 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "./fillit.h"
#include <stdlib.h>

void	*ft_error_map(t_map *map)
{
	if (map->content)
		ft_strdel(&map->content);
	ft_putstr("error\n");
	return (NULL);
}
