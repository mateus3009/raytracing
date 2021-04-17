/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 10:30:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	write_pixel(t_canvas canvas, int width, int height, t_pixel pixel)
{
	*(canvas.pixels + height * canvas.width + width) = pixel;
}
