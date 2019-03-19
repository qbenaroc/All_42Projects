/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:14:55 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 20:10:45 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}

void	ft_rot_x(double angle, int *y, int *z)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(angle) + prev_z * sin(angle);
	*z = prev_z * cos(angle) - prev_y * sin(angle);
}

void	ft_rot_y(double angle, int *x, int *z)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(angle) + prev_z * sin(angle);
	*z = prev_z * cos(angle) - prev_x * sin(angle);
}

void	ft_rot_z(double angle, int *x, int *y)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_y * cos(angle) + prev_x * sin(angle);
}

void	ft_reset_cam(t_env *fdf)
{
	fdf->cam.angle_x = 0;
	fdf->cam.angle_y = 0;
	fdf->cam.angle_z = 0;
}
