/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:55:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 12:39:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

bool	display_init_window(t_display *display)
{
	display->win = mlx_new_window(display->mlx,
		display->width, display->height, "MiniRT");
	if (!display->win)
		fatal("Failed to create a new window");
	mlx_hook(display->win, 33, 1L << 17, display_destroy, display);
	mlx_key_hook(display->win, display_handle_key, display);
	mlx_expose_hook(display->win, display_expose, display);
	mlx_loop(display->mlx);
	return (true);
}
