/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:22:36 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/11/08 12:17:27 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_error_display(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(2, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;

	if (argc != 2)
	{
		if (argc == 1)
			ft_error_display("File name missing.\n");
		else
			ft_error_display("Too many arguments.\n");
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (read(fd, &buff, 1) != 0)
			write(1, &buff, 1);
		close(fd);
	}
	return (0);
}
