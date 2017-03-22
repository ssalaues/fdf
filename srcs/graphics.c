/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:09:37 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/21 21:51:14 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	b_draw(t_fdf fdf, t_line l)
{
	while (l.x <= fdf.x1)
	{
		if (l.stp)
			mlx_pixel_put(fdf.mlx, fdf.win, l.y + X_OFF, l.x + Y_OFF, C_3);
		else if (fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x + X_OFF, l.y + Y_OFF, C_2);
		else if (!fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x + X_OFF, l.y + Y_OFF, C_1);
		printf("x: %d y: %d\n", l.x, l.y);
		l.err += l.derr;
		if (l.err > l.dx)
		{
			l.y += (fdf.y1 > fdf.y0 ? 1 : -1);
			l.err -= l.dx << 1;
		}
		l.x++;
	}
}

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
	b_draw(fdf, l);
}

void	d_hori(t_fdf fdf)
{
	fdf.x0 = (fdf.i * T_W) + (fdf.j * T_W);
	fdf.x1 = ((fdf.i + 1) * T_W) + (fdf.j * T_H);
	fdf.y0 = ((fdf.j * T_H) >> 1) - (((fdf.i * T_W) + (10 * fdf.h)) >> 1);
	fdf.y1 = ((fdf.j * T_H) >> 1) - ((((fdf.i + 1) * T_W) + (10 * fdf.ary[fdf.j][fdf.i + 1])) >> 1);
	b_line(fdf);
}

void	d_vert(t_fdf fdf)
{
	fdf.x0 = ((fdf.i * T_W) + (fdf.j * T_H));
	fdf.x1 = (fdf.i * T_W) + ((fdf.j + 1) * T_H);
	fdf.y0 = ((fdf.j * T_H) >> 1) - (((fdf.i * T_W) + (10 * fdf.h)) >> 1);
	fdf.y1 = (((fdf.j + 1) * T_H) >> 1) - (((fdf.i * T_W) + (10 * fdf.ary[fdf.j + 1][fdf.i])) >> 1);
	b_line(fdf);
}

int	graphics(t_fdf fdf)
{
	fdf.j = 0;
	while (fdf.j < fdf.y)
	{
		fdf.i = 1;
		while (fdf.i < fdf.x)
		{
			fdf.h = fdf.ary[fdf.j][fdf.i];
			if (fdf.i < fdf.x - 1)
				d_hori(fdf);
			if (fdf.j < fdf.y - 1)
				d_vert(fdf);
			fdf.i++;
		}
		fdf.j++;
	}
	return (0);
}
