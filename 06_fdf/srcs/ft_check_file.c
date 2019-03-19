/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:29:48 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 22:58:14 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_check_file_content(int fd)
{
	char	*line;
	int		ret;
	size_t	line_width;

	ret = get_next_line(fd, &line);
	if (ret == 0 || ret == -1)
	{
		ft_putendl_fd("No data found.", 2);
		return (-1);
	}
	line_width = ft_countcwords(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (line_width != ft_countcwords(line, ' '))
		{
			ft_putendl_fd("Wrong line length.", 2);
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

int				ft_check_file(char *av)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) < 0)
	{
		ft_putendl_fd("No data found.", 2);
		return (-1);
	}
	if (ft_check_file_content(fd) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
