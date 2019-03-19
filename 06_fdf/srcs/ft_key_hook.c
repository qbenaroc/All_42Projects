/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:18:18 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:27:56 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_manage_colors(int key, t_env *fdf)
{
	if (key == ONE)
		ft_init_colors(fdf, RED, CYAN, BLUE);
	else if (key == TWO)
		ft_init_colors(fdf, SNOW, GREEN, MAROON);
	else if (key == THREE)
		ft_init_colors(fdf, GOLD, DARK_SLATE_GRAY, AQUA_MARINE);
	else if (key == FOUR)
		ft_init_colors(fdf, SKY_BLUE, BEIGE, ORCHID);
	else if (key == FIVE)
		ft_init_colors(fdf, LAVENDER, SPRING_GREEN, HOT_PINK);
	else if (key == SIX)
		ft_init_colors(fdf, SEA_GREEN, FOREST_GREEN, DARK_GREEN);
	else if (key == SEVEN)
		ft_init_colors(fdf, SNOW, GREEN, MAROON);
	else if (key == EIGHT)
		ft_init_colors(fdf, SNOW, GREEN, MAROON);
	else if (key == NINE)
		ft_init_colors(fdf, SNOW, GREEN, MAROON);
	else if (key == ZERO)
		ft_init_colors(fdf, SNOW, GREEN, MAROON);
}

void	ft_manage_rot(int key, t_env *fdf)
{
	if (key == W)
		fdf->cam.angle_x -= 0.0872665;
	else if (key == S)
		fdf->cam.angle_x += 0.0872665;
	else if (key == A)
		fdf->cam.angle_y -= 0.0872665;
	else if (key == D)
		fdf->cam.angle_y += 0.0872665;
	else if (key == Q)
		fdf->cam.angle_z += 0.0872665;
	else if (key == E)
		fdf->cam.angle_z -= 0.0872665;
	else if (key == P || key == R)
	{
		if (key == P)
			fdf->cam.proj = (!fdf->cam.proj ? ISO : ORT);
		else
			ft_init_cam(fdf);
		ft_reset_cam(fdf);
	}
}

void	ft_manage_zoom(int key, t_env *fdf)
{
	if (key == MORE)
	{
		fdf->cam.space += 2;
		fdf->cam.trans_x -= fdf->map.nbcol;
		fdf->cam.trans_y -= fdf->map.nbline;
	}
	else if (key == LESS && fdf->cam.space >= 2)
	{
		fdf->cam.space -= 2;
		fdf->cam.trans_x += fdf->map.nbcol;
		fdf->cam.trans_y += fdf->map.nbline;
	}
	else if (key == M)
		fdf->cam.scale_z += 5;
	else if (key == L)
		fdf->cam.scale_z -= 5;
}

void	ft_manage_trans(int key, t_env *fdf)
{
	if (key == UP_A && fdf->cam.trans_y >= -fdf->map.nbline * fdf->cam.space)
		fdf->cam.trans_y -= 20;
	else if (key == L_A && fdf->cam.trans_x >= -fdf->map.nbcol * fdf->cam.space)
		fdf->cam.trans_x -= 20;
	else if (key == DWN_A && fdf->cam.trans_y <= WIN_HEIGHT)
		fdf->cam.trans_y += 20;
	else if (key == R_A && fdf->cam.trans_x <= WIN_WIDTH)
		fdf->cam.trans_x += 20;
}

/*
** Handle key press
*/

int		ft_key_hook(int key, t_env *fdf)
{
	if (key == ESC)
		ft_close(fdf);
	if (key == SPACE && fdf->main_img.isactive == FALSE)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->main_img.isactive = TRUE;
	}
	if (fdf->main_img.isactive == TRUE)
	{
		if (key == UP_A || key == DWN_A || key == L_A || key == R_A)
			ft_manage_trans(key, fdf);
		else if (key == MORE || key == LESS || key == M || key == L)
			ft_manage_zoom(key, fdf);
		else if (key == W || key == S || key == A || key == D || key == Q
				|| key == E || key == P || key == R)
			ft_manage_rot(key, fdf);
		else if (key == KEY_NBR)
			ft_manage_colors(key, fdf);
		ft_refresh_img(fdf);
	}
	return (0);
}
