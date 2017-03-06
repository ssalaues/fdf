/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:31:32 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 18:08:26 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		iso_x(t_fdf fdf)
{
	return (fdf.x * (TILE_W / 2) - fdf.y * (TILE_W / 2));
}
int		iso_y(t_fdf fdf)
{
	return (fdf.x * (TILE_H / 2) + fdf.y * (TILE_H / 2));
}

int		g_iso(t_fdf fdf)
{
	int	i;
	int *ary;

	while (fdf.y > 0)
	{
		i = **fdf.ary;
		ary = *fdf.ary;
		ary++;
		while(fdf.x > 0)
		{
			mlx_pixel_put(fdf.mlx, fdf.win, iso_x(fdf), iso_y(fdf), 0x007fffd4);
			fdf.x--;
			ary++;
		}
		fdf.y--;
		fdf.ary++;
	}
	return (0);
}
