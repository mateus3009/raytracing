/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/02 21:28:32 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

double	length(t_vector a)
{
	return (sqrt(dot(a, a)));
}
