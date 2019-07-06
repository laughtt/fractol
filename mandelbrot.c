/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 22:24:25 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 12:58:22 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>
#include <pthread.h>

int				ft_mandelbrot(t_fract *frac)
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
		a = frac->x - frac->y + frac->h;
		b = real + frac->w;
		n++;
	}
	return (n);
}
