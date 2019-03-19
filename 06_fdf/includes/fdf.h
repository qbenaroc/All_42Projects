/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:09:31 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:22:03 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <fdf_define.h>
# include <fdf_struct.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

int					ft_check_file(char *av);
void				ft_fdf(char *av);
int					ft_create_map(char *av, t_env *fdf);
void				ft_mlx(t_env *fdf);
int					ft_key_hook(int key, t_env *fdf);
int					ft_refresh_img(t_env *fdf);
void				ft_draw(t_env *fdf);
int					ft_close(t_env *fdf);
void				ft_bresenham(t_env *fdf);
void				ft_put_pixel_to_img(unsigned char *data, int x, int y
					, unsigned int color);
void				ft_select_points(t_env *fdf, int sens);
void				ft_iso(int *x, int *y, int z);
void				ft_rot_x(double angle, int *y, int *z);
void				ft_rot_y(double angle, int *x, int *z);
void				ft_rot_z(double angle, int *x, int *y);
void				ft_init_cam(t_env *fdf);
void				ft_init_colors(t_env *fdf, unsigned int pos
					, unsigned int def, unsigned int neg);
unsigned int		ft_get_point_color(t_env *fdf, int z);
unsigned int		ft_get_color(t_env *fdf);
void				ft_reset_cam(t_env *fdf);
void				ft_hud(t_env *fdf);

#endif
