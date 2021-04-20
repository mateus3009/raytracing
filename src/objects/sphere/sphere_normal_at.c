/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:30:11 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 17:06:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./sphere.h"

t_vector	sphere_normal_at(void	*data, t_point object_point)
{
	return (minus(object_point, point(0, 0, 0)));
}
