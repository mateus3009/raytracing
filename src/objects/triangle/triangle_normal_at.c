/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 22:28:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./triangle.h"

t_vector	triangle_normal_at(void	*data, t_point object_point)
{
	return (((t_triangle*)data)->normal);
}
