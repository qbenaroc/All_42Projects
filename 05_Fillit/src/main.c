/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:25:28 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/04 18:55:52 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int ac, char **av)
{
	int		fd;
	t_tetri	*file;
	t_map	*map;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (1);
	}
	if (fd < 0 || (file = read_file(fd)) == NULL)
	{
		ft_putendl("error");
		return (1);
	}
	map = solve(file);
	print_map(map);
	free_map(map);
	free_file(file);
	close(fd);
	return (0);
}
