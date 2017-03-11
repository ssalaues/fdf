/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:31:32 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/10 18:53:09 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		iso_x(int y, int x)
{
	return (X_OFF +(x * (TILE_W / 2) - y * (TILE_W / 2)));
}
int		iso_y(int x, int y, int h)
{
	return (Y_OFF +(x * (h / 2) + y * (h / 2)));
}
/*
void b_line(t_fdf fdf, int x1, int y1, int x2, int y2)
{
	int dx  = x2 - x1,
	dy  = y2 - y1,
	y   = y1,
	eps = 0;
	t_line l;

	l.ix = 0;
	l.iy = 0;
	for ( int x = x1; x <= x2; x++ )
	{
		if (!fdf.h)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, x + X_OFF, y + Y_OFF, 0x007fffd4);
			//mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0x007fffd4);
			//mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1)), (l.iy = iso_y(x1, y1, fdf.h)), 0x007fffd4);
			printf("turqoise x:%d y:%d  ",l.ix,l.iy);
		}
		else if (fdf.h)	
		{
		//	mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1)), (l.iy = iso_y(x1, y1, fdf.h)), 0x0000f000);
	//		mlx_pixel_put(fdf.mlx, fdf.win, iso_x(y1, x1), iso_y(x1, y1, fdf.h), 0x0000f000);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x1 + X_OFF), (l.iy = y1 + Y_OFF), 0x0000f000);
			printf("green x:%d y:%d  ",l.ix,l.iy);
		}
		eps += dy;
		if ((eps << 1) >= dx)
		{
			eps -= dx;
			y++;
		}
		x++;
	}
}
*/
void	b_line(t_fdf fdf, int x1, int y1, int x2, int y2)//Original Implementation of Bresenham's Line Algo
{
	int	dx;
	int	dy;
	int	y;
	int	x;
	int	eps;
	t_line	l;
	int	tmp;

	l.ix = 0;
	l.iy = 0;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	y = y1;
	x = x1;
	eps = 0;
	if (x1 > x2)
	{
		tmp = x2;;
		x2 = x1;
		x1 = tmp;
	}
	if (y1 > y2)
	{
		tmp = y2;
		y2 = x1;
		y1 = tmp;
	}
	while (x <= x2)	\\Y2 should be value + TILE_W
	{
		if (fdf.h)
		{
//			mlx_pixel_put(fdf.mlx, fdf.win, x + X_OFF, y + Y_OFF, 0x007fffd4);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1 + X_OFF)), (l.iy = iso_y(x1, y1 + Y_OFF, fdf.h)), 0x007fffd4);
			printf("turqoise x:%d y:%d  ",l.ix,l.iy);
		}
		else
		{
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1 + X_OFF)), (l.iy = iso_y(x1, y1 + Y_OFF, fdf.h)), 0x0000f000);
//			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x1 + X_OFF), (l.iy = y1 + Y_OFF), 0x0000f000);
			printf("green x:%d y:%d  ",l.ix,l.iy);
		}
		eps += dy;
		if ((eps << 1) >= dx)
		{
			eps -= dx;
			y++;
		}
		x++;
	}
}

int			g_iso(t_fdf fdf)
{
	int		i;
	int 	*ary;
	t_line	l;

	fdf.y1 = 0;
	i = fdf.x;
	l.ix = 0;
	l.iy = 0;
	while (fdf.y >= fdf.y1)
	{
		fdf.x1 = 0;
		ary = *fdf.ary;
		fdf.x = *ary;
		fdf.x--;
		ary++;
		while(fdf.x > fdf.x1)
		{
			fdf.h = *ary;
	//		mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(fdf.y1, fdf.x1)), (l.iy = iso_y(fdf.x1, fdf.y1, *ary)), 0x007fffd4);
//			b_line(fdf, fdf.x1, fdf.y1, iso_x(fdf.y1 + 1, fdf.x1 + 1), iso_y(fdf.x1 + 1, fdf.y1 + 1, *(ary + 1)));
			if (*ary == *(ary + 1))
				b_line(fdf, fdf.x1 * TILE_H, fdf.y1 * TILE_W, (fdf.x1 + 1) * TILE_H, (fdf.y1) * TILE_W);
			else
				b_line(fdf, fdf.x1 * TILE_H, fdf.y1 * TILE_W, (fdf.x1 + 1) * TILE_H, (fdf.y1 + 1) * TILE_W);
			printf("Tile:%d,%d Height:%d\n",fdf.x1,fdf.y1,*ary);
			ary++;
			fdf.x1++;
		}
		fdf.ary++;
		fdf.y1++;
	}
	printf("done with function\n");
	return (0);
}
