/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:03:40 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/04 18:06:42 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Check if the piece has 6 or 8 connections, if so it's valid
*/

int			piece_is_valid(char **array, int len)
{
	int		i;
	int		j;
	int		connections;

	j = 0;
	connections = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] == '#' && i - 1 >= 0 && array[j][i - 1] == '#')
				connections++;
			if (array[j][i] == '#' && i + 1 < len && array[j][i + 1] == '#')
				connections++;
			if (array[j][i] == '#' && j + 1 < len && array[j + 1][i] == '#')
				connections++;
			if (array[j][i] == '#' && j - 1 >= 0 && array[j - 1][i] == '#')
				connections++;
			i++;
		}
		j++;
	}
	return (connections == 6 || connections == 8);
}

/*
** Check all arrays of the file
** And reset all arrays on top left
*/

t_tetri		*check_maps(t_tetri **file)
{
	t_tetri	*current;
	size_t	len;

	current = *file;
	len = ft_strlen(current->array[0]);
	while (current)
	{
		if (!piece_is_valid(current->array, len))
		{
			free_file(*file);
			return (NULL);
		}
		else
		{
			reset_array(current);
			current->x = get_x_min(current->array, len);
			current->y = get_y_min(current->array, len);
			current->width = get_width(current->array);
			current->height = get_height(current->array);
		}
		current = current->next;
	}
	return (*file);
}
