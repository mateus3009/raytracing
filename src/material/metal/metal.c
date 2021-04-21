/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:33:55 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:52:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"

t_material	metal(void)
{
	t_material		material;

	material.data = NULL;
	material.scatter = metal_scatter;
	return (material);
}
