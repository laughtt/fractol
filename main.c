/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:33:18 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 11:49:25 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>
#include <pthread.h>

t_image			*create_image(t_win *win)
{
	t_image		*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(win->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}

void			img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT)
	{
		*(int*)(img->data + ((x + (y * IMG_WIDTH)) * img->bpp)) = color;
	}
}

t_image			*mlx_win_init(t_win *win)
{
	t_image		*image;

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr,\
			IMG_HEIGHT, IMG_WIDTH, "mlx 42");
	image = create_image(win);
	return (image);
}

int				main(int ac, char **argv)
{
	t_win		*win;
	t_fract		*frac;

	if (!(frac = malloc(sizeof(t_fract))))
		return (0);
	if (!(win = malloc(sizeof(t_win))))
		return (0);
	if (ac == 2 && ft_check_fractal(argv[1], frac))
	{
		frac->image = mlx_win_init(win);
		frac->win = win;
		ft_default_fract(frac);
		ft_draw_fractal(frac);
		mlx_hook(win->win_ptr, 4, 0, mouse_hook, frac);
		mlx_hook(win->win_ptr, 6, 0, mouse_move, frac);
		mlx_key_hook(win->win_ptr, hook_keydown, frac);
		mlx_loop(win->mlx_ptr);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \
				\"burningship\" \"tricorn\"");
	return (0);
}
