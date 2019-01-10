/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:25:05 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/07 12:27:09 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

size_t		lst_len(t_tetri *file)
{
	size_t i;

	i = 0;
	while (file)
	{
		file = file->next;
		i++;
	}
	return (i);
}

void		free_file(t_tetri *file)
{
	t_tetri *next;

	while (file)
	{
		next = file->next;
		free_array(file->array);
		ft_memdel((void**)&(file->array));
		ft_memdel((void**)&file);
		file = next;
	}
	ft_memdel((void**)&file);
}

/*
** Add a link to the end of the list
*/

void		tetri_add_end(t_tetri **alst, t_tetri *new)
{
	t_tetri *current;

	if (*alst)
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

/*
** Create a link of a tetrimino
*/

t_tetri		*new_tetri(char **array, char alph)
{
	t_tetri	*new;
	size_t	i;
	size_t	len;

	new = NULL;
	i = 0;
	len = ft_strlen(array[0]);
	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(new->array = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	while (i < len)
	{
		new->array[i] = ft_strdup(array[i]);
		i++;
	}
	new->width = 1;
	new->height = 1;
	new->x = get_x_min(new->array, len);
	new->y = get_y_min(new->array, len);
	new->alph = alph;
	new->next = NULL;
	return (new);
}

/*
** Create a new list of tetriminos, or add it to the living list
*/

t_tetri		*stock_tetri(t_tetri **file, char **array, size_t index)
{
	t_tetri *current;
	t_tetri *new;

	current = *file;
	if (index == 0)
		*file = new_tetri(array, 'A');
	else
	{
		new = new_tetri(array, 'A' + index);
		tetri_add_end(file, new);
	}
	return (current);
}
