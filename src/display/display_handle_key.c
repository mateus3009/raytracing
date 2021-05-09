/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_handle_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:11:17 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:09:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int	display_handle_key(int keynum, t_display *display)
{
	if (keynum == KEY_ESC)
		display_destroy(display);
	if (keynum == KEY_LEFT)
	{
		display->img_current--;
		display_expose(display);
	}
	if (keynum == KEY_RIGHT)
	{
		display->img_current++;
		display_expose(display);
	}
	return (1);
}
