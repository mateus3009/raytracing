/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 15:50:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	write_pixel(t_canvas canvas, int width, int height, t_pixel pixel)
{
	*(canvas.pixels + height * canvas.width + width) = pixel;
}
