/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:46:02 by dacuvill          #+#    #+#             */
/*   Updated: 2019/01/19 18:59:33 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"
#include "./libft/libft.h"

void	ft_print_res(char **smap)
{
	int	i;
	int	j;

	i = 0;
	while (smap[i])
	{
		j = 0;
		while (smap[i][j])
		{
			ft_putchar(smap[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
