/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:31:32 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/11 21:21:04 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		iso_x(int y, int x)
{
//	return ((x * (TILE_W / 2) - y * (TILE_W / 2)));
	return ((x - y) * TILE_W);
}
int		iso_y(int x, int y)
{
//	return ((x * (TILE_H / 2) + y * (TILE_H / 2)));
	return ((x + y) * TILE_H);
}
/*
void b_line(t_fdf fdf, int x1, int y1, int x2, int y2)
{
	int dx  = x2 - x1,
	dy  = y2 - y1,
	y   = y1,
	eps = 0;
	t_line l;
	int c1 = 0xfffd4;
	int c2 = 0xff34b3;

	l.ix = 0;
	l.iy = 0;
	for ( int x = x1; x <= x2; x++ )
	{
		if (!fdf.h)
		{
			//mlx_pixel_put(fdf.mlx, fdf.win, x + X_OFF, y + Y_OFF, 0xced1);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x + TILE_W), (l.iy = y + TILE_H), c1);
			//mlx_pixel_put(fdf.mlx, fdf.win, x, y, 0x007fffd4);
			//mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1)), (l.iy = iso_y(x1, y1, fdf.h)), 0x007fffd4);
			printf("turqoise x:%d y:%d  ",l.ix,l.iy);
		}
		else if (fdf.h)	
		{
		//	mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y1, x1)), (l.iy = iso_y(x1, y1, fdf.h)), 0x0000f000);
	//		mlx_pixel_put(fdf.mlx, fdf.win, iso_x(y1, x1), iso_y(x1, y1, fdf.h), 0x0000f000);
			//mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x1 + X_OFF), (l.iy = y1 + Y_OFF), 0xff34b3);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x + TILE_W), (l.iy = y + TILE_H), c2);
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
	int c1 = 0xfffd4;
	int c2 = 0xff34b3;

	l.ix = 0;
	l.iy = 0;
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
	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	y = y1;
	x = x1;
	eps = 0;
	while (x <= x2)	//Y2 should be value + TILE_W
	{
		if (fdf.h)
		{
//			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y, x)), (l.iy = iso_y(x, y)), 0x7fffd4);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x + TILE_W), (l.iy = y + TILE_H), c1);
			printf("fusia x:%d y:%d  ",l.ix,l.iy);
		}
		else
		{
//			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = iso_x(y, x)), (l.iy = iso_y(x, y)), 0xff34b3);
			mlx_pixel_put(fdf.mlx, fdf.win, (l.ix = x + TILE_W), (l.iy = y + TILE_H), c2);
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
		fdf.x = *ary * TILE_W;
		fdf.x--;
		ary++;
		while(fdf.x > fdf.x1)
		{
			fdf.h = *ary;
			b_line(fdf, fdf.x1, fdf.y1, (fdf.x1 + TILE_W), (fdf.y1 + TILE_W));
			b_line(fdf, fdf.x1, fdf.y1, (fdf.x1 + TILE_W), (fdf.y1));
			b_line(fdf, fdf.x1, fdf.y1, (fdf.x1), (fdf.y1 + TILE_W));
	//		b_line(fdf, fdf.x1 * TILE_W, fdf.y1 * TILE_H, (fdf.x1 + 1) * (TILE_W), (fdf.y1) * (TILE_H));
	//		b_line(fdf, iso_x(fdf.y1, fdf.x1), iso_y(fdf.x1, fdf.y1), iso_x(fdf.y1, fdf.x1 + (TILE_W)), iso_y(fdf.x1, fdf.y1 + (TILE_H)));
			printf("Tile:%d,%d Height:%d\n",fdf.x1,fdf.y1,*ary);
			ary++;
			fdf.x1 += TILE_W;
		}
		fdf.ary++;
		fdf.y1 += TILE_H;
	}
	printf("done with function\n");
	return (0);
}
