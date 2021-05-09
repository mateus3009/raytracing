/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normal_scatter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 16:27:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_normal.h"
#include "./../../objects/objects.h"

bool	color_normal_scatter(t_scatter_params p)
{
	*p.attenuation = divide(
			sum(normalize(p.record->normal), vector(1, 1, 1)), 2);
	return (false);
}
