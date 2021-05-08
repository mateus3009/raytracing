/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:13:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 12:14:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		display_destroy(t_display *display)
{
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	exit(EXIT_SUCCESS);
	return (1);
}
