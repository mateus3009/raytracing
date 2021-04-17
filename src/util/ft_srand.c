/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:36:29 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 21:49:49 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned long long int	g_seed;

void	ft_srand(unsigned long long int seed)
{
	g_seed = seed;
}
