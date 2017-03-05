/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:50:07 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 13:12:30 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

/* OLD ATOI ARRAY
t_fdf	ft_atoi_array(t_fdf fdf)
{
	int		**ary;
	int		b;

	b = 0;
	fdf.x = 0;
	ary = (int *)ft_memalloc(fdf.y);
	while (*fdf.store)
	{
		if (ft_isdigit(**fdf.store) || **fdf.store == '-')
		{
			*ary = ft_atoi(*fdf.store);
			if (b == 0)
			{
				fdf.ary = ary;
				b = 1;
			}
			ary++;
			fdf.x++;
		}
		fdf.store++;
	}
	return (fdf);
}*/
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
	
	ary = (int *)ft_memalloc(ft_numct(s) * sizeof(int));
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

	line = (char *)ft_memalloc(1);
	fdf.ary = (int **)ft_memalloc(sizeof(int**));
	fdf.y = 0;
	while(get_next_line(fd, &line))
	{
		fdf.ary[fdf.y] = ft_atoi_array(line);
		ft_strdel(&line);
		fdf.y++;
	}
	fdf.x = **fdf.ary;
	return (fdf);
}
