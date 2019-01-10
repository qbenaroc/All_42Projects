/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:12:21 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/12/30 17:12:23 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		print_map(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i++]);
		ft_putchar('\n');
	}
}

void		free_map(t_map *map)
{
	size_t i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*
** Allocate a new map with the size of sent parameter
** And fill its array with '.'
*/

t_map		*new_map(size_t size)
{
	t_map	*map;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->array = (char **)ft_memalloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		(map->array)[i] = ft_strnew(size);
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
