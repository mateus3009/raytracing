/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 12:39:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_camera.h"

void	test_canvas_init(void)
{
	t_canvas	canvas;
	int			row;
	int			column;
	t_tuple		black;

	printf("%s\n", __func__);
	canvas = canvas_init(20, 30);
	black = tuple(0, 0, 0, 0);
	assert(canvas.width == 20);
	assert(canvas.height == 30);
	row = 20;
	while (row--)
	{
		column = 30;
		while (column--)
			assert(tuple_equal(*(canvas.pixels + (row * 30) + column), black));
	}
	canvas_destroy(canvas);
}
