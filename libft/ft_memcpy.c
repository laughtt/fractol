/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:44:27 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/14 23:06:38 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
		size_t		i;
		char		*ptr;
		char		*ptr2;

		ptr = (char *)dst;
		ptr2 = (char *)src;
		i = -1;
		while (i++ < n)
			*(ptr + i) = (*ptr2 + i);
		return (dst);
}
