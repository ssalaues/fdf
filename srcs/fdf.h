/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/19 16:37:24 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define T_W 32
# define T_H 32
# define X_OFF	128
# define Y_OFF	512
# define C_1 0xfffd4
# define C_2 0xff34b3
# define C_3 0xff9ca
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_fdf
{
	int				**ary;
	int				x;
	int				y;
	int				y0;
	int				y1;
	int				y2;
	int				x0;
	int				x1;
	int				x2;
	int				i;
	int				j;
	int				h;
	void			*mlx;
	void			*win;
}					t_fdf;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				stp;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				derr;
	int				err;
}					t_line;

t_fdf				readin(int fd);
int					g_iso(t_fdf fdf);

#endif
