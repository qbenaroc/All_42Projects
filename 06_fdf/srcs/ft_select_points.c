/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:59:28 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 22:11:00 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		ft_select_1st_point(t_env *fdf)
{
	fdf->start.x = fdf->map.map[INDEX_PT][0] * fdf->cam.space;
	fdf->start.y = fdf->map.map[INDEX_PT][1] * fdf->cam.space;
	fdf->start.z = fdf->map.map[INDEX_PT][2] * fdf->cam.space / 16;
	if (fdf->start.z != 0)
		fdf->start.z = fdf->start.z + fdf->cam.scale_z;
	fdf->start.color = ft_get_point_color(fdf, fdf->start.z);
	ft_rot_x(fdf->cam.angle_x, &fdf->start.y, &fdf->start.z);
	ft_rot_y(fdf->cam.angle_y, &fdf->start.x, &fdf->start.z);
	ft_rot_z(fdf->cam.angle_z, &fdf->start.x, &fdf->start.y);
	if (fdf->cam.proj == ISO)
		ft_iso(&fdf->start.x, &fdf->start.y, fdf->start.z);
	fdf->start.x += fdf->cam.trans_x;
	fdf->start.y += fdf->cam.trans_y;
}

static void		ft_select_line_point(t_env *fdf)
{
	fdf->end.x = fdf->map.map[NEXT_PT_L][0] * fdf->cam.space;
	fdf->end.y = fdf->map.map[NEXT_PT_L][1] * fdf->cam.space;
	fdf->end.z = fdf->map.map[NEXT_PT_L][2] * fdf->cam.space / 16;
	if (fdf->end.z != 0)
		fdf->end.z = fdf->end.z + fdf->cam.scale_z;
	fdf->end.color = ft_get_point_color(fdf, fdf->end.z);
	ft_rot_x(fdf->cam.angle_x, &fdf->end.y, &fdf->end.z);
	ft_rot_y(fdf->cam.angle_y, &fdf->end.x, &fdf->end.z);
	ft_rot_z(fdf->cam.angle_z, &fdf->end.x, &fdf->end.y);
	if (fdf->cam.proj == ISO)
		ft_iso(&fdf->end.x, &fdf->end.y, fdf->end.z);
	fdf->end.x += fdf->cam.trans_x;
	fdf->end.y += fdf->cam.trans_y;
}

static void		ft_select_col_point(t_env *fdf)
{
	fdf->end.x = fdf->map.map[NEXT_PT_C][0] * fdf->cam.space;
	fdf->end.y = fdf->map.map[NEXT_PT_C][1] * fdf->cam.space;
	fdf->end.z = fdf->map.map[NEXT_PT_C][2] * fdf->cam.space / 16;
	if (fdf->end.z != 0)
		fdf->end.z = fdf->end.z + fdf->cam.scale_z;
	fdf->end.color = ft_get_point_color(fdf, fdf->end.z);
	ft_rot_x(fdf->cam.angle_x, &fdf->end.y, &fdf->end.z);
	ft_rot_y(fdf->cam.angle_y, &fdf->end.x, &fdf->end.z);
	ft_rot_z(fdf->cam.angle_z, &fdf->end.x, &fdf->end.y);
	if (fdf->cam.proj == ISO)
		ft_iso(&fdf->end.x, &fdf->end.y, fdf->end.z);
	fdf->end.x += fdf->cam.trans_x;
	fdf->end.y += fdf->cam.trans_y;
}

void			ft_select_points(t_env *fdf, int sens)
{
	if (sens == 0)
		ft_select_1st_point(fdf);
	else if (sens == 1)
		ft_select_line_point(fdf);
	else if (sens == 2)
		ft_select_col_point(fdf);
}
