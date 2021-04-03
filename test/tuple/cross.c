/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:13:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_cross_one(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	printf("%s\n", __func__);
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	c = cross(a, b);
	d = vector(-1, 2, -1);
	assert(tuple_equal(c, d));
}

void	test_cross_two(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	printf("%s\n", __func__);
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	c = cross(b, a);
	d = vector(1, -2, 1);
	assert(tuple_equal(c, d));
}
