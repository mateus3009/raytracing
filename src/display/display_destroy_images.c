/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_destroy_images.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:41:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 13:09:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	display_destroy_images(t_display *display)
{
	int		index;
	t_img	i;

	if (display->imgs)
	{
		index = -1;
		while (++index < display->img_count)
		{
			i = display->imgs[index];
			if (i.img)
				mlx_destroy_image(display->mlx, i.img);
		}
		free(display->imgs);
	}
}
