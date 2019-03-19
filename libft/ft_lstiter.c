/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:00:29 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/15 11:22:37 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstiter(t_list	*lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	if (lst -> next)
		ft_lstiter(lst->next, f);
	f(lst);
}
