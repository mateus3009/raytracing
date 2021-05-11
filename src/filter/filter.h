/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:03:36 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 02:09:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H

#include "./../util/util.h"
#include "./../tuple/tuple.h"

struct							s_object;
struct							s_intersection;

typedef struct s_object			t_object;
typedef struct s_intersection	t_intersection;

t_pixel							filter_rainbow(t_intersection *rec);
t_pixel							filter(t_intersection *rec);

#endif
