/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:52:24 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/03 16:47:27 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	free_array(char **array)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(array[0]);
	while (i < len)
		ft_memdel((void**)&(array[i++]));
}

/*
** Fill array with '.' if no '#' or '.'
*/

void	empty_fill(char **array, int len)
{
	int i;
	int j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] != '.' && array[j][i] != '#')
				array[j][i] = '.';
			i++;
		}
		j++;
	}
}

/*
** Reset the array on the top left corner
*/

void	reset_array(t_tetri *tetri)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(tetri->array[0]);
	if (tetri->x != 0)
	{
		while (i < len)
		{
			ft_strncpy(tetri->array[i], tetri->array[i] + tetri->x, len);
			i++;
		}
	}
	i = 0;
	if (tetri->y != 0)
	{
		while (i + tetri->y < len)
		{
			ft_strncpy(tetri->array[i], tetri->array[i + tetri->y], len);
			i++;
		}
		while (i < len)
			ft_bzero(tetri->array[i++], len);
	}
	empty_fill(tetri->array, len);
}
