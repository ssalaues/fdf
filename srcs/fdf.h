/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 21:04:17 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TILE_W 32
# define TILE_H 32
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
	int				y2;
	int				x;
	int				x2;
	int				h;
	void			*mlx;
	void			*win;
}					t_fdf;

t_fdf				readin(int fd);
int					*ft_atoi_array(const char *s);
int					g_iso(t_fdf fdf);

#endif
