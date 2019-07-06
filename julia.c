/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:38:30 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 12:55:53 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int				julia(t_fract *frac)
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
		real = 2.0f * a * b;
		a = frac->x - frac->y - frac->xx;
		b = real - frac->yy;
		n++;
	}
	return (n);
}
