/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 18:03:22 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TILE_W 64
# define TILE_H 64
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
	int				x;
	int				h;
	void			*mlx;
	void			*win;
}					t_fdf;

t_fdf				readin(int fd);
int					*ft_atoi_array(const char *s);
int					g_iso(t_fdf fdf);

#endif
