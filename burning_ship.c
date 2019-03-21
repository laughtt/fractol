/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:38:26 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 00:08:21 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int			burning_ship(t_fract *frac)
{
	int		n;
	float	com;
	float	real;
	float	a;
	float	b;

	a = frac->h;
	b = frac->w;
	n = 0;
	while (n < frac->maxiter)
	{
		com = pow(a, 2) - pow(b, 2);
		real = 2.0f * fabs(a * b);
		a = com + frac->h;
		b = real + frac->w;
		n++;
		if (a*a + b*b > 4)
			break;
	}
	return (n);
}
