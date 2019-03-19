/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:27:37 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 22:29:02 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				nbline;
	int				nbcol;
}					t_map;

typedef struct		s_cam
{
	int				space;
	int				trans_x;
	int				trans_y;
	double			angle_x;
	double			angle_y;
	double			angle_z;
	double			scale_z;
	int				proj;
}					t_cam;

typedef struct		s_img
{
	void			*img_ptr;
	unsigned char	*data;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	pos_color;
	unsigned int	def_color;
	unsigned int	neg_color;
	int				isactive;
}					t_img;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	unsigned int	color;
}					t_point;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_map	map;
	struct s_img	main_img;
	struct s_cam	cam;
	struct s_point	start;
	struct s_point	current;
	struct s_point	end;
	struct s_point	delta;
}					t_env;

#endif
