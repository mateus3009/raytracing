/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:25:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:30:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	transform_ray(t_ray r, t_matrix matrix)
{
	return (ray(matrix_product(matrix, r.origin),
			matrix_product(matrix, r.direction)));
}
