/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:50:07 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/07 17:14:55 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

int		countline(const char *s)
{
	int c;

	c = 0;
	while (*s)
	{
		s++;
		if (*s == '\n' || !*s)
			c++;
	}
	return (c);
}

int		ft_numct(const char *s)
{
	int	ct;

	ct = 0;
	while (*s)
	{
		if (ft_isdigit(*s) && !ft_isdigit(*(s + 1)))
			ct++;
		s++;
	}
	return (ct);
}
int		*ft_atoi_array(const char *s)
{
	int	*ary;
	int	i;
	
	ary = (int*)ft_memalloc((ft_numct(s) * sizeof(int)) + 1);
	i = 1;
	while(*s)
	{
		if (ft_isdigit(*s) || *s == '-')
		{
			ary[i] = ft_atoi(s);
			i++;
		}
		s = ((ft_wordlen(s, ' ')) ? s + ft_wordlen(s, ' ') : s + 1);
	}
	ary[0] = i;
	return (ary);
}

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
	fdf.x = **fdf.ary;
	fdf.y--;
	return (fdf);
}
