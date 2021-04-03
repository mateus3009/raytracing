/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:04:54 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:11:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_point_one(void)
{
	t_point	a;
	t_point	b;

	printf("%s\n", __func__);
	a = (t_point){.x = 1, .y = 2, .z = 3, .w = 1};
	b = point(1, 2, 3);
	assert(tuple_equal(a, b));
}

void	test_point_two(void)
{
	t_point	a;
	t_point	b;

	printf("%s\n", __func__);
	a = (t_point){.x = 4, .y = 3, .z = 2, .w = 1};
	b = point(4, 3, 2);
	assert(tuple_equal(a, b));
}
