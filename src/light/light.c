/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:21:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 22:01:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

bool	light(t_light **light,
	double brightness,
	t_pixel color,
	t_point origin)
{
	*light = malloc(sizeof(t_light));
	if (!*light)
		return (false);
	**light = (t_light){.color = color, .origin = origin, .brightness = brightness};
	return (true);
}
