/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_unit_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:37 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 23:54:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	random_unit_sphere(void)
{
	return (normalize(random_in_unit_sphere()));
}
