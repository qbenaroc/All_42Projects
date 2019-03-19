/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:25:03 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:32:20 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Refresh the image, put img to window and destroy it
*/

int		ft_refresh_img(t_env *fdf)
{
	fdf->main_img.img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->main_img.data = (unsigned char*)mlx_get_data_addr(fdf->main_img.img_ptr
		, &(fdf->main_img.bpp), &(fdf->main_img.size_line)
		, &(fdf->main_img.endian));
	ft_draw(fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr
		, fdf->main_img.img_ptr, 0, 0);
	ft_hud(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->main_img.img_ptr);
	return (0);
}
