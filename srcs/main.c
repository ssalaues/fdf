/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:13 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/11 19:54:32 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;


	if (ac >= 2)
	{
		fdf = readin(open(av[1], O_RDONLY));
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, ft_atoi(av[2]), ft_atoi(av[3]), av[4]);
		printf("y:%d\nx:%d\n", fdf.y, fdf.x);
		g_iso(fdf);
		printf("test");
		mlx_loop(fdf.mlx);
	}
	return (0);
}
