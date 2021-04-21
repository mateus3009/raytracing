/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:24:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 21:53:18 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "./../tuple/tuple.h"

/*
** ambient		[0, 1]
** diffuse		[0, 1]
** specular		[0, 1]
** shininess	[10, 200]
*/

typedef struct s_material
{
	t_pixel	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_material;

t_material		material(void);

#endif
