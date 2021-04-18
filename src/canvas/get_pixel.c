/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 16:23:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_pixel	get_pixel(t_canvas canvas, int width, int height)
{
	if (width < 0 || canvas.width < width
		|| height < 0 || canvas.height < height)
		return (pixel(0, 0, 0));
	return (*(canvas.pixels + height * canvas.width + width));
}
