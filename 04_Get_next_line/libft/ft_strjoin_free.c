/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:26:24 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/11/30 16:32:31 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	char *res;

	res = NULL;
	if (s1 && s2)
	{
		res = ft_strjoin(s1, s2);
		if (n == 1)
			free(s1);
		else if (n == 2)
			free(s2);
		else if (n == 3)
		{
			free(s1);
			free(s2);
		}
	}
	return (res);
}
