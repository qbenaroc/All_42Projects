/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:27:21 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 21:05:22 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_start_page(t_env *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, (WIN_WIDTH / 2) - 105
			, (WIN_HEIGHT / 2) - 25, WHITE, "Press \"Space\" to start");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, (WIN_WIDTH / 2) - 100
			, WIN_HEIGHT - 50, CORAL, "Developed by qbenaroc");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, (WIN_WIDTH / 2) - 55
			, 50, GOLD, "FDF Project");
}

/*
** Manage mouse, keys, and no events
*/

void	ft_mlx(t_env *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	ft_start_page(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, ft_key_hook, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close, fdf);
	mlx_loop(fdf->mlx_ptr);
}
