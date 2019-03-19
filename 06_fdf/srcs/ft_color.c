/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:06:45 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 22:20:23 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static double			ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static unsigned int		ft_get_light(unsigned int start, unsigned int end
									, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

unsigned int			ft_get_color(t_env *fdf)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			percent;

	if (fdf->current.color == fdf->end.color)
		return (fdf->current.color);
	if (fdf->delta.x > fdf->delta.y)
		percent = ft_percent(fdf->start.x, fdf->end.x, fdf->current.x);
	else
		percent = ft_percent(fdf->start.y, fdf->end.y, fdf->current.y);
	red = ft_get_light(fdf->start.color & 0xFF, fdf->end.color & 0xFF, percent);
	green = ft_get_light((fdf->start.color >> 8) & 0xFF
			, (fdf->end.color >> 8) & 0xFF, percent);
	blue = ft_get_light((fdf->start.color >> 16) & 0xFF
			, (fdf->end.color >> 16) & 0xFF, percent);
	return (red | (green << 8) | (blue << 16));
}

unsigned int			ft_get_point_color(t_env *fdf, int z)
{
	if (z > 0)
		return (fdf->main_img.pos_color);
	else if (z < 0)
		return (fdf->main_img.neg_color);
	else
		return (fdf->main_img.def_color);
}
