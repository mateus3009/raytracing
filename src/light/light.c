/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:21:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 11:23:10 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	light(t_pixel intensity, t_point origin)
{
	return ((t_light){.intensity = intensity, .origin = origin});
}
