/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:45:23 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/14 23:07:52 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*ptr;
	size_t		i;

	ptr = (char *)dst;
	i = -1;
	while (++i < n)
	{
		*(ptr + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
		{
			*(ptr + i + 1) = '\0';
		   return (dst + i + 1);	
		}
	}
	*(ptr + i) = '\0';
	return (NULL);
}
