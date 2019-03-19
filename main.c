/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:33:18 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/19 16:00:38 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>


int				hook_keydown(int key, void *parameter)
{
	(void)parameter;

	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

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

int			ft_mandelbrot(t_fract *frac)
{
	int		n;
	float	com;
	float	real;
	float	a;
	float	b;

	a = frac->h;
	b = frac->w;
	n = 0;
	while (n < ITERATIONS)
	{
		com = pow(a, 2) - pow(b, 2);
		real = 2.0f * a * b;
		a = com + frac->h;
		b = real + frac->w;
		n++;
		if (fabs(a*a + b*b) > 16)
			break;
	}
	return (n);
}

void		ft_choose_color(t_fract *frac)
{
	int color;

	color = frac->iter;
	if (color < ITERATIONS && color > 0)
		frac->color = 0;
	else 
		frac->color = 0xFFFFFF;
}
void		ft_convert_to_coordinate(t_fract *frac)
{
	 
	frac->w = (float)(frac->w - frac->loopw) / frac->size;
	frac->h = (float)(frac->h - frac->looph) / frac->size;
}

void		ft_calculate_color(t_fract  *frac)
{
	ft_convert_to_coordinate(frac);
	frac->iter = ft_mandelbrot(frac);
	ft_choose_color(frac);
}

void		ft_draw_fractal(t_fract *frac)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (h < IMG_HEIGHT)
	{
		while (w < IMG_WIDTH)
		{
			frac->w = w;
			frac->h = h;
			ft_calculate_color(frac);
			img_pixel_put(frac->image,h,w,frac->color);
			w++;
		}
		w = 0;
		h++;
	}
}

t_image		*mlx_win_init(t_win	*win)
{
	t_image		*image;

   	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, IMG_HEIGHT, IMG_WIDTH, "mlx 42");
	image = create_image(win);
	return (image);
}

void		ft_default_fract(t_fract *frac)
{
	frac->loopw = IMG_WIDTH / 2;
	frac->looph = IMG_HEIGHT / 2;
	frac->size = INIT_ZOOM;
	frac->disx = 0;
	frac->disy = 0;
}
int			main(int ac, char **argv)
{
	t_win		*win;
	t_fract 	*frac;

	if (!(frac = malloc(sizeof(t_fract))))
		return (0);
	if (!(win = malloc(sizeof(t_win))))
		return (0);
	if (ac == 2)
	{
		if (*argv[1] == 'a')
			return (1);
		frac->image = mlx_win_init(win);
		frac->win = win;
		ft_default_fract(frac);
		ft_draw_fractal(frac);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, frac->image->ptr, 0, 0);
		mlx_key_hook(win->win_ptr, hook_keydown, (void*)0);
		mlx_hook(win->win_ptr , 4, 0 , mouse_hook, frac);
		mlx_loop(win->mlx_ptr);
		free(win);
		free(frac);
	}
	else
		ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}                     