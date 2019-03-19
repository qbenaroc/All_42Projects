/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:38:41 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 21:36:23 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		ft_draw_single_column(t_env *fdf)
{
	while (fdf->map.y < fdf->map.nbline - 1)
	{
		ft_select_points(fdf, 2);
		fdf->current = fdf->start;
		ft_bresenham(fdf);
		fdf->map.y++;
		fdf->start = fdf->end;
	}
}

static void		ft_draw_columns(t_env *fdf)
{
	fdf->map.x = 0;
	while (fdf->map.x < fdf->map.nbcol)
	{
		fdf->map.y = 0;
		ft_select_points(fdf, 0);
		ft_draw_single_column(fdf);
		fdf->map.x++;
	}
}

static void		ft_draw_single_line(t_env *fdf)
{
	while (fdf->map.x < fdf->map.nbcol - 1)
	{
		ft_select_points(fdf, 1);
		fdf->current = fdf->start;
		ft_bresenham(fdf);
		fdf->map.x++;
		fdf->start = fdf->end;
	}
}

static void		ft_draw_lines(t_env *fdf)
{
	fdf->map.y = 0;
	while (fdf->map.y < fdf->map.nbline)
	{
		fdf->map.x = 0;
		ft_select_points(fdf, 0);
		ft_draw_single_line(fdf);
		fdf->map.y++;
	}
}

void			ft_draw(t_env *fdf)
{
	ft_draw_lines(fdf);
	ft_draw_columns(fdf);
}
