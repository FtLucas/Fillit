/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 04:15:48 by dacuvill          #+#    #+#             */
/*   Updated: 2018/11/26 14:14:04 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nl;
	t_list	*cl;
	t_list	*cf;

	if (!(lst && f))
		return (NULL);
	cf = (*f)(lst);
	if (!(nl = ft_lstnew(cf->content, cf->content_size)))
		return (NULL);
	cl = nl;
	lst = lst->next;
	while (lst)
	{
		cf = (*f)(lst);
		if (!(cl->next = ft_lstnew(cf->content, cf->content_size)))
			return (NULL);
		cl = cl->next;
		lst = lst->next;
	}
	return (nl);
}
