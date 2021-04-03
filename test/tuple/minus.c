/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:42:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_minus_one(void)
{
	t_point		a;
	t_point		b;
	t_vector	c;
	t_vector	d;

	printf("%s\n", __func__);
	a = point(3, 2, 1);
	b = point(5, 6, 7);
	c = vector(-2, -4, -6);
	d = minus(a, b);
	assert(tuple_equal(c, d));
}

void	test_minus_two(void)
{
	t_point		a;
	t_vector	b;
	t_point		c;
	t_point		d;

	printf("%s\n", __func__);
	a = point(3, 2, 1);
	b = vector(5, 6, 7);
	c = point(-2, -4, -6);
	d = minus(a, b);
	assert(tuple_equal(c, d));
}

void	test_minus_three(void)
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_vector	d;

	printf("%s\n", __func__);
	a = vector(3, 2, 1);
	b = vector(5, 6, 7);
	c = vector(-2, -4, -6);
	d = minus(a, b);
	assert(tuple_equal(c, d));
}
