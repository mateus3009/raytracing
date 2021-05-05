/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:31:21 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 23:52:47 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disk.h"

bool	disk(t_object **obj)
{
	*obj = object(0);
	if (!*obj)
		return (false);
	(*obj)->intersect = disk_intersect;
	(*obj)->normal_at = disk_normal_at;
	return (true);
}
