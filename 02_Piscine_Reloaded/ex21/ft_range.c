/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:36:43 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/11/06 16:56:31 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*range;
	int i;

	range = NULL;
	i = 0;
	if (min >= max)
		return (range);
	else
	{
		if (!(range = (int*)malloc(sizeof(int) * max - min)))
			return (0);
		while (min < max)
		{
			range[i] = min;
			i++;
			min++;
		}
		return (range);
	}
}
