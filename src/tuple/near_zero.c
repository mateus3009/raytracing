/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   near_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:21:58 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:59:44 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

bool	near_zero(t_tuple t)
{
	double	k;

	k = .0001;
	return (fabs(t.x) < k
		&& fabs(t.y) < k
		&& fabs(t.z) < k);
}
