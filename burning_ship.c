/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:38:26 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 13:02:43 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int				burning_ship(t_fract *frac)
{
	int			n;
	float		real;
	float		a;
	float		b;

	a = frac->h;
	b = frac->w;
	n = 0;
	while (n < frac->maxiter)
	{
		frac->x = a * a;
		frac->y = b * b;
		if (frac->x + frac->y > 4)
			break ;
		real = 2.0f * fabs(a * b);
		a = frac->x - frac->y + frac->h;
		b = real + frac->w;
		n++;
	}
	return (n);
}
