/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_vector_in_unit_disk.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:37 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 22:36:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	random_vector_in_unit_disk(void)
{
	t_vector	v;

	while (true)
	{
		v = vector(ft_rand_range(-1, 1), ft_rand_range(-1, 1), 0);
		if (length(v) >= 1)
			continue ;
		return (v);
	}
}
