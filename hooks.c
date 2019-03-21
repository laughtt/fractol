/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:35:51 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 11:24:57 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

void	ft_zoom(int x, int y, t_fract *frac)
{
	frac->disx = (-IMG_WIDTH / 2 + y) * (INIT_ZOOM / frac->size) ;
	frac->disy = (-IMG_HEIGHT / 2 + x) * (INIT_ZOOM / frac->size) ;
	frac->loopw = y ;
	frac->looph = x ;
	frac->size = frac->size * 120 / 100;
	if (frac->numbf == 2)
		frac->maxiter += 30;
	ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
	ft_draw_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr, frac->image->ptr,0,0);
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

int	mouse_move(int x, int y, t_fract *frac)
{
	if (frac->numbf == 2)
	{
		if (x > 0 && x < IMG_HEIGHT && y > 0 && y < IMG_WIDTH)
		{
			frac->xx = x - IMG_HEIGHT / 2;
			frac->yy = y - IMG_WIDTH / 2;
			frac->xx = ((float)(x-IMG_HEIGHT/2) / (float)(-IMG_HEIGHT/2 - IMG_HEIGHT/2)) * (-2.0f) + 1.0f;
			frac->yy = ((float)(y-IMG_WIDTH /2) / (float)(-IMG_WIDTH/2 - IMG_WIDTH/2)) * (-2.0f) + 1.0f;
			ft_bzero(frac->image->data, IMG_WIDTH * IMG_HEIGHT * frac->image->bpp);
			ft_draw_fractal(frac);
			mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr, frac->image->ptr, 0, 0);
		}	
	}
	return (0);
}

int				hook_keydown(int key, t_fract *frac)
{
	if (key == 126)
		ft_up(frac);
	if (key == 125)
		ft_down(frac);
	if (key == 124)
		ft_right(frac);
	if (key == 123)
		ft_left(frac);
	if (key == 37)
		ft_color_change(frac);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

