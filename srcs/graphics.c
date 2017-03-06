/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:31:32 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 21:07:24 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		iso_x(int y, int x)
{
	return (x * (TILE_W / 2) - y * (TILE_W / 2));
}
int		iso_y(int x, int y, int h)
{
	return (x * (h / 2) + y * (h / 2));
}

//void	b_line(t_fdf fdf)

int		g_iso(t_fdf fdf)
{
	int	i;
	int	x;
	int y;
	int *ary;

	y = 0;
	i = fdf.x;
	while (fdf.y > y)
	{
		x = 0;
		ary = *fdf.ary;
		fdf.x = *ary;
		ary++;
		while(fdf.x > x)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, 256 + iso_x(y, x), 32 + iso_y(x, y, *ary), 0x007fffd4);
			ary++;
			x++;
		}
		fdf.ary++;
		y++;
	}
	return (0);
}
