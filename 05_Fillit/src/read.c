/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:46:00 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/07 12:26:44 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Divide the file big string in tetri-list
*/

t_tetri		*read_tetris(char *file_content)
{
	t_tetri		*file;
	char		**array;
	size_t		i;
	size_t		j;

	file = NULL;
	i = 0;
	j = 0;
	if (!(array = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (file_content[i])
	{
		if ((i + 1) % 4 == 0 && i != 0)
			array[j++] = ft_strsub(file_content, i - 3, 4);
		if (j == 4)
		{
			stock_tetri(&file, array, i / 16);
			free_array(array);
			j = 0;
		}
		i++;
	}
	ft_memdel((void**)&array);
	free(file_content);
	return (check_maps(&file));
}

/*
** Read the file, check the content and return a list of tetris
*/

t_tetri		*read_file(int fd)
{
	char		buff[22];
	char		*file_content;
	int			ret;

	file_content = ft_strnew(0);
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (!check_buff_content(buff))
		{
			free(file_content);
			return (NULL);
		}
		file_content = ft_strjoin_free(file_content
				, ft_strsplit_to_str(buff, '\n'), 3);
	}
	if (ret == 0 && buff[20] == '\0' && ft_strlen(file_content) <= MAX_CHAR)
		return (read_tetris(file_content));
	free(file_content);
	return (NULL);
}
