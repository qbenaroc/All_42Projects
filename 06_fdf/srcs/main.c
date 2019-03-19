/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:26:02 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/01/17 17:57:16 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Usage : ./fdf <source_file>", 2);
		return (-1);
	}
	else if (ft_check_file(av[1]) == -1)
		return (-1);
	ft_fdf(av[1]);
	return (0);
}
