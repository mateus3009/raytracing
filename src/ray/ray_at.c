/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:03:24 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/13 22:04:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point	ray_at(t_ray ray, double t)
{
	return (sum(ray.origin, scalar(ray.direction, t)));
}