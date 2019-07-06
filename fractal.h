/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:20:48 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/22 13:02:45 by jcarpio-         ###   ########.fr       */
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
# define PTHRE 6
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
	float		xx;
	float		yy;
	int			maxiter;
	int			disx;
	int			disy;
	int			numbf;
	int			cnbr;
	int			xt;
	int			xt_max;
}					t_fract;

void				ft_copy_str(t_fract *cp, t_fract *frac);
int					ft_mandelbrot(t_fract *frac);
t_image				*mlx_win_init(t_win *win);
void				img_pixel_put(t_image *img, int x, int y, int color);
void				ft_calculate_color(t_fract *frac);
void				ft_choose_color(t_fract *frac);
void				*draw(void	*fract);
void				ft_calculate_color(t_fract *frac);
void				*draw(void *fract);
void				ft_convert_to_coordinate(t_fract *fract);
int					ft_check_fractal(char *str, t_fract *frac);
void				ft_color_change(t_fract *frac);
void				ft_left(t_fract *frac);
void				ft_right(t_fract *frac);
void				ft_down(t_fract *frac);
int					hook_keydown(int key, t_fract *frac);
void				ft_up(t_fract *frac);
int					tricorn(t_fract *fract);
int					burning_ship(t_fract *frac);
int					*color_array(int a);
int					julia(t_fract *frac);
void				ft_default_fract(t_fract *frac);
void				ft_draw_fractal(t_fract *frac);
t_image				*create_image(t_win	*win);
void				ft_draw_fractal(t_fract *frac);
void				ft_zoom(int x, int y, t_fract *frac);
void				ft_dezoom(int x, int y, t_fract *frac);
int					mouse_hook(int mousecode, int x, int y, t_fract *frac);
int					mouse_move(int	x, int	y, t_fract *frac);
#endif
