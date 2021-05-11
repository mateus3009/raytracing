/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:17:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 01:35:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"
#include "./../objects/objects.h"

t_pixel	filter_rainbow(t_intersection *rec)
{
	return (divide(
		sum(normalize(rec->normal), vector(1, 1, 1)), 2));
}
