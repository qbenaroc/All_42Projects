/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:32:18 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/07 12:27:47 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_CHAR 416

# include <libft.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	char			**array;
	size_t			width;
	size_t			height;
	size_t			x;
	size_t			y;
	char			alph;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	size_t			size;
	char			**array;
}					t_map;

t_tetri				*read_file(int fd);
int					check_buff_content(char buff[]);
t_tetri				*stock_tetri(t_tetri **file, char **array, size_t index);
t_tetri				*check_maps(t_tetri **file);
size_t				lst_len(t_tetri *file);
void				free_file(t_tetri *file);
void				free_array(char **array);
void				reset_array(t_tetri *tetri);
int					get_x_min(char **array, int len);
int					get_y_min(char **array, int len);
size_t				get_width(char **array);
size_t				get_height(char **array);
t_map				*solve(t_tetri *file);
t_map				*new_map(size_t size);
void				print_map(t_map *map);
void				free_map(t_map *map);

#endif
