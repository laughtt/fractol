/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:38:14 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 20:41:35 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

void	ft_up(t_fract *frac)
{
	frac->loopw *= 0.9f;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
}

void	ft_down(t_fract *frac)
{
	frac->loopw *= 1.1f;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
}

void	ft_right(t_fract *frac)
{
	frac->looph *= 0.9f;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
}

void	ft_left(t_fract *frac)
{
	frac->looph *= 1.1f;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
}

void	ft_color_change(t_fract *frac)
{
	frac->cnbr = rand();
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * 4);
	ft_draw_fractal(frac);
}
