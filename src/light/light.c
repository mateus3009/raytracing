/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:21:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/07 21:28:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

bool	light(t_light **light,
	double brightness,
	t_pixel color,
	t_point origin)
{
	if (brightness < 0 || 1 < brightness)
		return (false);
	*light = malloc(sizeof(t_light));
	if (!*light)
		return (false);
	**light = (t_light){.color = scalar(color, brightness), .origin = origin};
	return (true);
}
