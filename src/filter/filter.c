/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:11:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:09:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
#include "./../objects/objects.h"

t_pixel	filter(t_intersection *rec)
{
	if (!rec->object.filter)
		return (rec->object.material.color);
	return (rec->object.filter(rec));
}
