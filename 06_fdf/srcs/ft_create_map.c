/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:40 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:10:39 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Put the nbr of lines and columns in fdf struct
*/

static int		ft_count_map_size(char *av, t_env *fdf)
{
	char	*line;
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	get_next_line(fd, &line);
	fdf->map.nbline++;
	fdf->map.nbcol = ft_countcwords(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		fdf->map.nbline++;
		free(line);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

/*
** Parse the file in **int
*/

static int		ft_parse_map(t_env *fdf, int fd)
{
	char	*line;
	char	**split_line;
	int		i;

	i = 0;
	if (!(fdf->map.map = ft_tab_new_int(3, fdf->map.nbline * fdf->map.nbcol)))
		return (-1);
	while (get_next_line(fd, &line))
	{
		split_line = ft_strsplit(line, ' ');
		fdf->map.x = 0;
		while (split_line[fdf->map.x])
		{
			fdf->map.map[i][0] = fdf->map.x;
			fdf->map.map[i][1] = fdf->map.y;
			fdf->map.map[i][2] = atoi(split_line[fdf->map.x]);
			free(split_line[fdf->map.x]);
			i++;
			fdf->map.x++;
		}
		free(split_line);
		free(line);
		fdf->map.y++;
	}
	return (0);
}

/*
** Create map struct
*/

int				ft_create_map(char *av, t_env *fdf)
{
	int fd;

	ft_count_map_size(av, fdf);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	ft_parse_map(fdf, fd);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
