/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_to_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:28:25 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 21:29:04 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_put_pixel_to_img(unsigned char *data, int x, int y
						, unsigned int color)
{
	size_t i;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		i = (x * 4 + 4 * WIN_WIDTH * y);
		data[i] = (data[i] == 0 ? color & 0xFF : data[i]);
		i++;
		data[i] = (data[i] == 0 ? color >> 8 & 0xFF : data[i]);
		i++;
		data[i] = (data[i] == 0 ? color >> 16 & 0xFF : data[i]);
	}
}
