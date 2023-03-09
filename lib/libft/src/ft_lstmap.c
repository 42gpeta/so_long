/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:50:09 by gpeta             #+#    #+#             */
/*   Updated: 2022/12/23 17:37:53 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*last;
	t_list	*nlist;

	if (!lst || !f || !del)
		return (NULL);
	nlist = 0;
	last = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		if (last)
			last->next = tmp;
		else
			nlist = tmp;
		last = tmp;
		lst = lst->next;
	}
	return (nlist);
}
