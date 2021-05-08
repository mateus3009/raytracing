/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_handle_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:11:17 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 12:11:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		display_handle_key(int keynum, t_display *display)
{
	if (keynum == KEY_ESC)
		display_destroy(display);
	return (1);
}
