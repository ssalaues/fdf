/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 11:09:01 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_fdf
{
	int				**ary;
	int				y;
	int				x;
	int				h;
	char			**store;
}					t_fdf;

t_fdf				readin(int fd);
int					*ft_atoi_array(const char *s);

#endif
