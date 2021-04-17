/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:24:38 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 10:25:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_vector	reflect(t_vector vector, t_vector normal)
{
	return (minus(vector, scalar(normal, 2. * dot(vector, normal))));
}
