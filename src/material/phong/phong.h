/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:28:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 22:58:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONG_H
# define PHONG_H

# include "./../material.h"
# include "./../../world/world.h"

/*
** ambient		[0, 1]
** diffuse		[0, 1]
** specular		[0, 1]
** shininess	[10, 200]
*/

typedef struct s_phong
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_phong;

bool			phong_scatter(t_scatter_params p);
t_material		phong(t_pixel color,
					double ambient,
					double diffuse,
					double specular,
					double shininess);

#endif
