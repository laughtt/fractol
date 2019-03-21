/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:07:59 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 00:24:12 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int			tricorn(t_fract *frac)
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
		com = pow(a, 2) - pow(b, 2) + frac->h;
		real = -2.0f * a * b + frac->w;
		a = com + frac->h;
		b = real + frac->w;
		n++;
		if (a*a + b*b > 4)
			break;
	}
	return (n);
}
