/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:12:13 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/17 14:09:53 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Print the piece with its alph on the map
** If '.' is called it resets at the x, y coordonances
*/

void		print_piece(t_map *map, t_tetri *file, char c)
{
	size_t i;
	size_t j;
	size_t len;

	j = 0;
	len = ft_strlen(file->array[0]);
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (file->array[j][i] == '#')
				map->array[j + file->y][i + file->x] = c;
			i++;
		}
		j++;
	}
}

/*
** Try to place the Tetri at x and y coordonances
*/

int			place_piece(t_map *map, t_tetri *file)
{
	size_t i;
	size_t j;
	size_t len;

	j = 0;
	len = ft_strlen(file->array[0]);
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (file->array[j][i] == '#'
					&& map->array[j + file->y][i + file->x] != '.')
				return (0);
			i++;
		}
		j++;
	}
	print_piece(map, file, file->alph);
	return (1);
}

/*
** Backtracking
*/

int			solve_file(t_map *map, t_tetri *file)
{
	if (!file)
		return (1);
	file->y = 0;
	while (file->y + file->height - 1 < map->size)
	{
		file->x = 0;
		while (file->x + file->width - 1 < map->size)
		{
			if (place_piece(map, file))
			{
				if (solve_file(map, file->next))
					return (1);
				else
					print_piece(map, file, '.');
			}
			file->x++;
		}
		file->y++;
	}
	return (0);
}

size_t		hight_sqrt(size_t n)
{
	size_t size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Makes the map bigger until the backtracking finds a solution
*/

t_map		*solve(t_tetri *file)
{
	t_map	*map;
	size_t	size;

	size = hight_sqrt(lst_len(file) * 4);
	map = new_map(size);
	while (!solve_file(map, file))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	return (map);
}
