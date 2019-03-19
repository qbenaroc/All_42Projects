/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:24:11 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:00:56 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			ft_init_colors(t_env *fdf, unsigned int pos, unsigned int def
							, unsigned int neg)
{
	fdf->main_img.pos_color = pos;
	fdf->main_img.def_color = def;
	fdf->main_img.neg_color = neg;
}

static void		ft_init_space(t_env *fdf)
{
	if (fdf->map.nbcol <= 20)
		fdf->cam.space = 50;
	else if (fdf->map.nbcol > 20 && fdf->map.nbcol <= 50)
		fdf->cam.space = 25;
	else if (fdf->map.nbcol > 50 && fdf->map.nbcol <= 100)
		fdf->cam.space = 15;
	else if (fdf->map.nbcol > 100 && fdf->map.nbcol <= 200)
		fdf->cam.space = 5;
	else
		fdf->cam.space = 1;
}

void			ft_init_cam(t_env *fdf)
{
	ft_init_space(fdf);
	fdf->cam.trans_x = (WIN_WIDTH - (fdf->map.nbcol * fdf->cam.space)) / 2;
	fdf->cam.trans_y = (WIN_HEIGHT - (fdf->map.nbline * fdf->cam.space)) / 2;
	fdf->cam.scale_z = 0;
}

void			ft_fdf(char *av)
{
	t_env fdf;

	ft_bzero(&fdf, sizeof(t_env));
	ft_create_map(av, &fdf);
	ft_init_colors(&fdf, RED, CYAN, BLUE);
	ft_init_cam(&fdf);
	ft_mlx(&fdf);
}
