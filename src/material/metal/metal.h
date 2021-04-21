/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:14:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:52:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	METAL_H
# define METAL_H

# include "./../material.h"

t_material		metal(void);
bool			metal_scatter(
					t_material material,
					t_ray r_in,
					t_intersection rec,
					t_pixel *attenuation,
					t_ray *scattered);

#endif
