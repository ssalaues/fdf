/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:13 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/05 10:14:02 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
		fdf = readin(open(av[1], O_RDONLY));
		printf("%d\n", **fdf.ary);
		printf("y:%d\nx:%d\n", fdf.y, fdf.x);
	return (0);
}
