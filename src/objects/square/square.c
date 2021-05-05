/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:54:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

bool	square(t_object **obj)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = square_intersect;
	(*obj)->normal_at = square_normal_at;
	return (true);
}
