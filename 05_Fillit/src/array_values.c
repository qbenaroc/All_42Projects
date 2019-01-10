/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:14:04 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/03 17:05:33 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Get the x min on an array
*/

int			get_x_min(char **array, int len)
{
	int i;
	int j;
	int min;

	j = 0;
	min = len - 1;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] == '#' && min > i)
				min = i;
			i++;
		}
		j++;
	}
	return (min);
}

/*
** Get the y min on an array
*/

int			get_y_min(char **array, int len)
{
	int i;
	int j;
	int min;

	j = 0;
	min = len - 1;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] == '#' && min > j)
				min = j;
			i++;
		}
		j++;
	}
	return (min);
}

/*
** Get the '#' max on x
*/

size_t		get_width(char **array)
{
	size_t i;
	size_t j;
	size_t len;
	size_t width;

	j = 0;
	width = 0;
	len = ft_strlen(array[0]);
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] == '#' && width < i)
				width = i;
			i++;
		}
		j++;
	}
	return (width + 1);
}

/*
** Get the '#' max on y
*/

size_t		get_height(char **array)
{
	size_t i;
	size_t j;
	size_t len;
	size_t height;

	j = 0;
	height = 0;
	len = ft_strlen(array[0]);
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (array[j][i] == '#' && height < j)
				height = j;
			i++;
		}
		j++;
	}
	return (height + 1);
}
