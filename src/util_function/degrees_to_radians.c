/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrees_to_radians.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:28:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/04 09:38:33 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_function.h"

double	degrees_to_radians(double degrees)
{
	return ((degrees / 180) * PI);
}
