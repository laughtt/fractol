/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:27:51 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/03/21 11:00:13 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*color_array(int	a)
{
	static int		array[15];

	array[0] = 0x421e0f / a;
	array[1] = 0x19071a / a;
	array[2] = 0x09012f * a;
	array[3] = 0x040449 / a;
	array[4] = 0x0c2c8a / a;
	array[5] = 0x1852b1 * a;
	array[6] = 0x397dd1 * a;
	array[7] = 0x86b5e5 * a;
	array[8] = 0xd3ecf8 * a;
	array[9] = 0xd3ecf8 * a;
	array[10] = 0xf8c95f * a;
	array[11] = 0xffaa00 / a;
	array[12] = 0xcc8000 / a;
	array[13] = 0x995700 / a;
	array[14] = 0x6a3403 / a;
	return (array);
}
