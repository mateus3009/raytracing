/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:29:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 11:45:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	canvas_destroy(t_canvas canvas)
{
	if (canvas.pixels)
		free(canvas.pixels);
}
