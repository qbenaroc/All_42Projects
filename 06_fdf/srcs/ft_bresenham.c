/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:01:06 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 21:37:30 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			ft_bresenham(t_env *fdf)
{
	fdf->delta.x = (abs(fdf->end.x - fdf->start.x));
	fdf->delta.sx = (fdf->start.x < fdf->end.x ? 1 : -1);
	fdf->delta.y = (abs(fdf->end.y - fdf->start.y));
	fdf->delta.sy = (fdf->start.y < fdf->end.y ? 1 : -1);
	fdf->delta.err = (fdf->delta.x > fdf->delta.y ? fdf->delta.x
					: -fdf->delta.y) / 2;
	while (1)
	{
		ft_put_pixel_to_img(fdf->main_img.data, fdf->current.x, fdf->current.y
						, ft_get_color(fdf));
		if (fdf->current.x == fdf->end.x && fdf->current.y == fdf->end.y)
			break ;
		fdf->delta.e2 = fdf->delta.err;
		if (fdf->delta.e2 > -fdf->delta.x)
		{
			fdf->delta.err -= fdf->delta.y;
			fdf->current.x += fdf->delta.sx;
		}
		if (fdf->delta.e2 < fdf->delta.y)
		{
			fdf->delta.err += fdf->delta.x;
			fdf->current.y += fdf->delta.sy;
		}
	}
}
