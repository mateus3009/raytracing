/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 16:03:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	canvas_init(int width, int height)
{
	t_pixel	*pixels;

	pixels = ft_calloc(width * height, sizeof(t_pixel));
	return ((t_canvas){
		.width = width,
		.height = height,
		.pixels = pixels});
}
