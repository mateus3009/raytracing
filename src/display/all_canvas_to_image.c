/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_canvas_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:38:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:10:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

unsigned int	create_final_color(t_pixel c)
{
	unsigned int	r;

	r = 0;
	r = r | ((int)clamp(c.r * 255, 0, 255)) << 16;
	r = r | ((int)clamp(c.g * 255, 0, 255)) << 8;
	r = r | ((int)clamp(c.b * 255, 0, 255));
	return (r);
}

static void	display_write_pixel(t_img *img, t_pixel color, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(unsigned int *)dst = create_final_color(color);
}

static void	canvas_to_image(t_img *img, t_canvas *canvas)
{
	int	x;
	int	y;

	y = -1;
	while (++y < canvas->height)
	{
		x = -1;
		while (++x < canvas->width)
			display_write_pixel(img, get_pixel(*canvas,
					x, canvas->height - 1 - y), x, y);
	}
}

bool	all_canvas_to_images(t_list *canvas, t_display *display)
{
	int	index;

	if (!display_init_images(display, ft_lstsize(canvas)))
		return (false);
	index = 0;
	while (canvas)
	{
		canvas_to_image(&(display->imgs[index]), (t_canvas *)canvas->content);
		canvas = canvas->next;
		index++;
	}
	return (true);
}
