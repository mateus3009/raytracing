/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_tuple_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:37 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 18:40:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	random_tuple_range(double min, double max)
{
	return (tuple(
		ft_rand_range(min, max),
		ft_rand_range(min, max),
		ft_rand_range(min, max),
		ft_rand_range(min, max)));
}
