/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_ppm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:08:28 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 16:04:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	canvas_to_ppm(t_canvas canvas)
{
	int		row;
	int		column;
	t_pixel	pixel;

	printf("P3\n%d %d\n255\n", canvas.width, canvas.height);
	row = canvas.height;
	while (row--)
	{
		column = canvas.width;
		while (column--)
		{
			pixel = *(canvas.pixels + (row * canvas.width) + column);
			printf("%.f %.f %.f\n", pixel.r, pixel.g, pixel.b);
		}
	}
}
