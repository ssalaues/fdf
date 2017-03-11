/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/10 19:30:47 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TILE_W 4
# define TILE_H 4
# define X_OFF	256
# define Y_OFF	256
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_fdf
{
	int				**ary;
	int				y;
	int				y1;
	int				y2;
	int				x;
	int				x1;
	int				x2;
	int				h;
	void			*mlx;
	void			*win;
}					t_fdf;

typedef struct		s_line
{
	int				ix;
	int				iy;
}					t_line;

t_fdf				readin(int fd);
int					*ft_atoi_array(const char *s);
int					g_iso(t_fdf fdf);

#endif
