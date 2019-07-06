/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:36:09 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 11:50:32 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			ft_check_fractal(char *str, t_fract *frac)
{
	if (!ft_strcmp(str, "mandelbrot"))
		frac->numbf = 1;
	else if (!ft_strcmp(str, "julia"))
		frac->numbf = 2;
	else if (!ft_strcmp(str, "burningship"))
		frac->numbf = 3;
	else if (!ft_strcmp(str, "tricorn"))
		frac->numbf = 4;
	else
		return (0);
	return (1);
}

void		ft_default_fract(t_fract *frac)
{
	frac->loopw = IMG_WIDTH / 2;
	frac->looph = IMG_HEIGHT / 2;
	frac->size = INIT_ZOOM;
	frac->disx = 0;
	frac->disy = 0;
	frac->xx = -0.70176;
	frac->yy = -0.3842;
	frac->maxiter = ITERATIONS;
	frac->cnbr = 1;
}

void		ft_copy_str(t_fract *cp, t_fract *frac)
{
	cp->h = frac->h;
	cp->w = frac->w;
	cp->looph = frac->looph;
	cp->loopw = frac->loopw;
	cp->size = frac->size;
	cp->color = frac->color;
	cp->iter = frac->iter;
	cp->image = frac->image;
	cp->win = frac->win;
	cp->y = frac->y;
	cp->x = frac->x;
	cp->xx = frac->xx;
	cp->yy = frac->yy;
	cp->maxiter = frac->maxiter;
	cp->disx = frac->disx;
	cp->disy = frac->disy;
	cp->numbf = frac->numbf;
	cp->cnbr = frac->cnbr;
}
