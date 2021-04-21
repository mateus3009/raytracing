/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_in_hemispere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:37 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 23:55:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	random_in_hemispere(t_vector normal)
{
	t_vector	random;

	random = random_in_unit_sphere();
	if (dot(normal, random) > 0)
		return (random);
	return (scalar(random, -1));
}
