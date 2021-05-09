/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:13:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:08:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	display_destroy(t_display *display)
{
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	display_destroy_images(display);
	exit(EXIT_SUCCESS);
	return (1);
}
