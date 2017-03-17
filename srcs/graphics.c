/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:09:37 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/16 20:39:55 by ssalaues         ###   ########.fr       */
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

void	d_hori(t_fdf fdf)
{
	fdf.x0 = (fdf.i + fdf.j) * (T_W >> 1);
	fdf.x1 = ((fdf.i + 1) + fdf.j) * (T_W >> 1);
	fdf.y0 = (((fdf.j)  >> 1) - (fdf.i + fdf.h)) * (T_H >> 1);
	fdf.y1 = (((fdf.j) >> 1) -  ((fdf.i + 1) + fdf.ary[fdf.j][fdf.i + 1])) * (T_H >> 1);
	b_line(fdf);
}

void	d_vert(t_fdf fdf)
{
	fdf.x0 = (fdf.i + fdf.j) * (T_W >> 1);
	fdf.x1 = ((fdf.i) + (fdf.j + 1)) * (T_W >> 1);
	fdf.y0 = (((fdf.j)  >> 1) - (fdf.i + fdf.h)) * (T_H >> 1);
	fdf.y1 = (((fdf.j + 1) >> 1) -  (fdf.i + fdf.ary[fdf.j + 1][fdf.i])) * (T_H >> 1);
	b_line(fdf);
}
/*
int	g_iso(t_fdf fdf)
{
	fdf.j = 0;
	while (fdf.j * T_H < fdf.y)
	{
		fdf.i = 0;
		while (fdf.i < fdf.x - 1)
		{
			fdf.h = fdf.ary[fdf.j][fdf.i];
			d_hori(fdf);
			fdf.i++;
		}
		fdf.j++;
	}
	fdf.j = 0;
	while (fdf.j * T_H < fdf.y - 1)
	{
		fdf.i = 0;
		while (fdf.i < fdf.x)
		{
			fdf.h = fdf.ary[fdf.j][fdf.i];
			d_vert(fdf);
			fdf.i++;
		}
		fdf.j++;
	}
	return (0);
}
*/

int	g_iso(t_fdf fdf)
{

	fdf.i = 0;
	while (fdf.i < fdf.x / T_W)
	{
		fdf.j = 0;
		while (fdf.j < fdf.y / T_H)
		{
			d_hori(fdf);
			d_vert(fdf);
			fdf.j++;
		}
		fdf.i++;
	}
	return (0);
}
/*
int	g_init(t_fdf fdf)
{
	
}*/
