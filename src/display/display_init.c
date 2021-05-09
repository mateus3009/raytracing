/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:55:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:08:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

bool	display_init(t_display *display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
		fatal("Failed to initiate the mlx");
	mlx_get_screen_size(display->mlx, &display->width, &display->height);
	display->win = NULL;
	display->imgs = NULL;
	display->img_count = 0;
	display->img_current = 0;
	return (true);
}
