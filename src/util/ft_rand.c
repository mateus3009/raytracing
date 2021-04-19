/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:36:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 23:37:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned long long int	g_seed;

double	ft_rand(void)
{
	g_seed = g_seed * 281474977 + 2345;
	return (fabs(cos((unsigned long int)(g_seed % 25214903917))));
}
