/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/21 22:30:32 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define T_W 8
# define T_H 8
# define X_OFF	fdf.t_w
# define Y_OFF	fdf.t_h
# define C_1 0xfffd4
# define C_2 0xff34b3
# define C_3 0xcc9ca
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx_keys_mac.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

typedef struct		s_fdf
{
	int				**ary;
	int				x;
	int				y;
	int				y0;
	int				y1;
	int				x0;
	int				x1;
	int				i;
	int				j;
	int				h;
	int				t_w;
	int				t_h;
	char			*file;
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
int					graphics(t_fdf *fdf);

#endif
