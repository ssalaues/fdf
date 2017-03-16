/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:50:07 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/15 14:44:36 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

t_fdf	readin(int	fd)
{
	char	*line;
	t_fdf	fdf;

	line = (char*)ft_memalloc(1);
	fdf.ary = (int **)ft_memalloc(256 * sizeof(int**));
	fdf.y = 0;
	while(get_next_line(fd, &line))
	{
		fdf.ary[fdf.y] = ft_atoi_array(line);
		ft_strdel(&line);
		fdf.y++;
	}
	fdf.x = **fdf.ary * T_W;
	fdf.y--;
	fdf.y *= T_H;
	return (fdf);
}
