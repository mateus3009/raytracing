/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:14:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 10:55:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COLOR_NORMAL_H
# define COLOR_NORMAL_H

# include "./../material.h"

t_material		color_normal(void);
bool			color_normal_scatter(
					t_material material,
					t_ray r_in,
					t_intersection rec,
					t_pixel *attenuation,
					t_ray *scattered);

#endif
