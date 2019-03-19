/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:20:48 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/18 19:55:15 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "miniLibX/mlx.h"
# include "libft/libft.h"
# define IMG_WIDTH 512
# define IMG_HEIGHT 512
# define ITERATIONS 100
# define INIT_ZOOM 100
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	char		*str;
}					t_image;

typedef struct		s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}					t_win;

typedef	struct		s_frac
{
	float		h;
	float		w;
	int			looph;
	int			loopw;
	int			size;
	int			color;
	int			iter;
	t_image		*image;
	t_win		*win;
	float		y;
	float		x;
	int			disx;
	int			disy;
}					t_fract;

void		ft_default_fract(t_fract *frac);
void		ft_draw_fractal(t_fract *frac);
t_image 	*create_image(t_win *win);
void		ft_draw_fractal(t_fract *frac);
void		ft_zoom(int x, int y, t_fract *frac);
void		ft_dezoom(int x, int y, t_fract *frac);
int			mouse_hook(int mousecode, int x, int y, t_fract *frac);
#endif
