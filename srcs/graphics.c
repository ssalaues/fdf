/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:09:37 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/16 16:39:37 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	b_line(t_fdf fdf, int x0, int y0, int x1, int y1)
void	b_line(t_fdf fdf)
{
	t_line l;
	
	l.stp = 0;
	if (ft_abs(fdf.x0 - fdf.x1) < ft_abs(fdf.y0 - fdf.y1))
	{
		ft_swap(&fdf.x0, &fdf.y0);
		ft_swap(&fdf.x1, &fdf.y1);
		l.stp = 1;
	}
	if (fdf.x0 > fdf.x1)
	{
		ft_swap(&fdf.x0, &fdf.x1);
		ft_swap(&fdf.y0, &fdf.y1);
	}
	l.dx = fdf.x1 - fdf.x0;
	l.dy = fdf.y1 - fdf.y0;
	l.derr = ft_abs(l.dy) << 1;
	l.err = 0;
	l.y = fdf.y0;
	l.x = fdf.x0;
	while (l.x <= fdf.x1)
	{
		if (l.stp)
			mlx_pixel_put(fdf.mlx, fdf.win, l.y, l.x, C_3);
		else if (fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x, l.y, C_2);
		else if (!fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x, l.y, C_1);
		l.err += l.derr;
		if (l.err > l.dx)
		{
			l.y += (fdf.y1 > fdf.y0 ? 1 : -1);
			l.err -= l.dx << 1;
		}
		l.x++;
	}
}
/*
void	d_hori(t_fdf fdf)
{
	fdf.x0 = (fdf.i + fdf.j) * T_W >> 1;
	fdf.x1 = ((fdf.i + 1) + fdf.j) * T_W >> 1;
	fdf.y0 = (((fdf.j)  >> 1) - (fdf.i + fdf.ary[j][i])) * T_H >> 1;
	fdf.y1 = (((fdf.j + 1) >> 1) -  fdf.i) * T_H >> 1;
	b_line(fdf);
}*/

int	g_iso(t_fdf fdf)
{

	fdf.i = 0;
	while (fdf.i < fdf.x / T_W)
	{
//		fdf.ary[i][j];
		fdf.j = 0;
		while (fdf.j < fdf.y / T_H)
		{
			fdf.h = fdf.ary[fdf.j][fdf.i];
			fdf.x0 = ((fdf.i) + fdf.j)* T_W >> 1;
			fdf.y0 = ((fdf.j + 1) + fdf.i) * T_H >> 1; // havent figured out y axis
			fdf.x1 =((fdf.i + 1) + fdf.j) * T_W >> 1;
			fdf.y1 = ((fdf.j + 1) + fdf.i) * T_H >> 1; // havent figured out y axis
//			b_line(fdf,(x + 1)* T_W / 2, (y + 1) * T_H / 2, (x + 1) * T_W / 2, (y + 1) * T_H / 2);
//			b_line(fdf, fdf.x0, fdf.y0, fdf.x1, fdf.y1);
			b_line(fdf);
			fdf.j++;
		}
		fdf.i++;
		fdf.x1 =(fdf.i + 1) * T_W / 2;
//		b_line(fdf, fdf.x0, fdf.y0, fdf.x1, fdf.y1);
	}
	return (0);
}
/*
int	g_init(t_fdf fdf)
{
	
}*/
