/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:36:09 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 17:19:51 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_check_fractal(char *str, t_fract *frac)
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
