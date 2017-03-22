/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:13 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/21 22:48:44 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_h(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_LEFT)
		fdf->t_w -= 15;
	if (keycode == KEY_RIGHT)
		fdf->t_w += 15;
	if (keycode == KEY_UP)
		fdf->t_h -= 10;
	if (keycode == KEY_DOWN)
		fdf->t_h += 10;
	if (keycode == KEY_Z)
		fdf->t_s += 4;
	if (keycode == KEY_O)
		fdf->t_s -= 4;
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_string_put(fdf->mlx, fdf->win, 75, 30, C_1, fdf->file);
	mlx_string_put(fdf->mlx, fdf->win, 25, 30, C_2, "test:");
	graphics(fdf);
	return (0);
}

t_fdf	readin(int	fd)
{
	char	*line;
	t_fdf	fdf;

	line = (char*)ft_memalloc(1);
	fdf.ary = (int **)ft_memalloc(256 * sizeof(int**));
	fdf.y = 0;
	while(get_next_line(fd, &line))
	{
		fdf.ary[fdf.y] = ft_atoi_array(line);
		ft_strdel(&line);
		fdf.y++;
	}
	fdf.x = **fdf.ary;
	return (fdf);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	
	if (ac >= 2)
	{
		fdf = readin(open(av[1], O_RDONLY));
		fdf.file = 1 + ft_strrchr(av[1], '/');
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, (fdf.t_w = 2000), (fdf.t_h = 1000), "fdf");
		fdf.t_w = 1000 - (sqrt(pow(fdf.x, 2) + pow(fdf.y, 2)) * 2.);
		fdf.t_h = 500 + (fdf.y >> 1);
		fdf.t_s = 8;
		mlx_string_put(fdf.mlx, fdf.win, 75, 30, C_1, fdf.file);
		mlx_string_put(fdf.mlx, fdf.win, 25, 30, C_2, "File:");
		mlx_expose_hook(fdf.win, &graphics, &fdf);
		mlx_key_hook(fdf.win, &key_h, &fdf);
	//	graphics(fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_putstr("\tDude, Don't forget arguments\n");
	return (0);
}
