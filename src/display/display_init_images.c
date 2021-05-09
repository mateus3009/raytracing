/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:41:06 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 12:42:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

bool	display_init_images(t_display *display, int size)
{
	int		index;
	t_img	i;

	display->img_count = size;
	display->imgs = ft_calloc(sizeof(t_img), display->img_count);
	if (!display->imgs)
		return (false);
	index = -1;
	while (++index < size)
	{
		i.img = mlx_new_image(display->mlx, display->width, display->height);
		i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_size, &i.endian);
		if (!i.img || !i.addr)
		{
			display_destroy_images(display);
			return (false);
		}
		display->imgs[index] = i;
	}
	return (true);
}
