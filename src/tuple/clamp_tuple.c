/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:09:24 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:35:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	clamp_tuple(t_tuple t, double min, double max)
{
	return (tuple(
			clamp(t.x, min, max),
			clamp(t.y, min, max),
			clamp(t.z, min, max),
			clamp(t.w, min, max)));
}
