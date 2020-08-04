/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:51:58 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/25 12:38:41 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lnew;

	if (!(lnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		lnew->content = NULL;
		lnew->content_size = 0;
		lnew->next = NULL;
	}
	else
	{
		if (!(lnew->content = (t_list *)malloc(sizeof(t_list) * content_size)))
		{
			free(lnew);
			return (NULL);
		}
		ft_memcpy(lnew->content, content, content_size);
		lnew->content_size = content_size;
		lnew->next = NULL;
	}
	return (lnew);
}
