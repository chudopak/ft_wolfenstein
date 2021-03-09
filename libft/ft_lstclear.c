/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:27:37 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/09 16:34:34 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
