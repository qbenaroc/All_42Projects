/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 17:30:28 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/04 18:58:37 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Strlen function until meeting char c
*/

size_t		strlen_until_c(char str[], char c)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i + 1);
}

/*
** If there is only '#', '.' and '\n' and 4 x '#'
*/

int			check_char_type(char str[])
{
	int i;
	int sharps;

	i = 0;
	sharps = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			sharps++;
		i++;
	}
	if (sharps != 4)
		return (0);
	return (1);
}

/*
** Check char type in buff
** and the form of buff
** and if the len of each lines of buff is equal to 5
*/

int			check_buff_content(char buff[])
{
	int i;

	i = 0;
	if (!check_char_type(buff))
		return (0);
	if (buff[20] != '\n' && buff[20] != '\0')
		return (0);
	while (i < 4)
	{
		if (strlen_until_c(buff + (i * 5), '\n') != 5)
			return (0);
		i++;
	}
	return (1);
}
