/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:35:51 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/19 15:49:12 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

void	ft_zoom(int x, int y, t_fract *frac)
{
	frac->disx = (-IMG_WIDTH / 2 + y) * (INIT_ZOOM / frac->size) ;
	frac->disy = (-IMG_HEIGHT / 2 + x) * (INIT_ZOOM / frac->size) ;
	frac->loopw = y + frac->disx;
	frac->looph = x + frac->disx;
	frac->size = frac->size * 120 / 100;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr, frac->image->ptr,0,0);
	printf("x %d  fy %d \n" , x ,y);
}

void	ft_dezoom(int x, int y, t_fract *frac)
{
	x = 0;
	y = 0;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_default_fract(frac);
	ft_draw_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr, frac->image->ptr, 0, 0);
}

int		mouse_hook(int mousecode, int x, int y, t_fract *frac)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, frac);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, frac);
	return (0);
}

