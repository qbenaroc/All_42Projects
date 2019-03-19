/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:23:45 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:14:20 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_hud(t_env *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 0, WHITE
			, "Translations : Arrows");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 20, WHITE
			, "Rotations    : Q E A D W S");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 40, WHITE
			, "Projection   : P");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 60, WHITE
			, "Reset        : R");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 80, WHITE
			, "Zoom         : + / -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 100, WHITE
			, "Scale_z      : M / L");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 120, WHITE
			, "Colors       : 1 - 9");
}
