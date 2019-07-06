/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 22:20:57 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 12:45:59 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>
#include <pthread.h>

void			ft_convert_to_coordinate(t_fract *frac)
{
	frac->w = (float)(frac->w - frac->loopw) / frac->size;
	frac->h = (float)(frac->h - frac->looph) / frac->size;
}

void			ft_draw_fractal(t_fract *frac)
{
	pthread_t		t[PTHRE];
	int				i;
	t_fract			tab[PTHRE];

	i = 0;
	while (i < PTHRE)
	{
		ft_copy_str(&tab[i], frac);
		tab[i].xt = IMG_WIDTH / PTHRE * i;
		tab[i].xt_max = (IMG_WIDTH / PTHRE) * (i + 1);
		pthread_create(&t[i], NULL, draw, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,\
			frac->image->ptr, 0, 0);
}

void			*draw(void *fract)
{
	int			w;
	t_fract		*frac;
	int			h;

	frac = (t_fract *)fract;
	h = 0;
	w = frac->xt;
	while (h < IMG_HEIGHT)
	{
		while (w < frac->xt_max)
		{
			frac->w = w;
			frac->h = h;
			ft_calculate_color(frac);
			img_pixel_put(frac->image, h, w, frac->color);
			w++;
		}
		w = 0;
		h++;
	}
	return (frac);
}

void			ft_calculate_color(t_fract *frac)
{
	ft_convert_to_coordinate(frac);
	if (frac->numbf == 1)
		frac->iter = ft_mandelbrot(frac);
	if (frac->numbf == 2)
		frac->iter = julia(frac);
	if (frac->numbf == 3)
		frac->iter = burning_ship(frac);
	if (frac->numbf == 4)
		frac->iter = tricorn(frac);
	ft_choose_color(frac);
}

void			ft_choose_color(t_fract *frac)
{
	int		colors;
	int		map;

	colors = 14;
	map = frac->iter % colors;
	frac->color = (color_array(frac->cnbr))[map];
}
