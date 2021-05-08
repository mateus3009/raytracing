/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_expose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:12:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 12:12:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	display_expose(t_display *display)
{
	if (!display->imgs)
		return (1);
	mlx_clear_window(display->mlx, display->win);
	mlx_put_image_to_window(display->mlx, display->win,
		display->imgs[display->img_current].img, 0, 0);
	return (1);
}
