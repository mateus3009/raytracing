/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:11:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_sum_one(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	printf("%s\n", __func__);
	a = tuple(1, 2, 3, 4);
	b = tuple(4, 3, 2, 1);
	c = tuple(5, 5, 5, 5);
	d = sum(a, b);
	assert(tuple_equal(c, d));
}

void	test_sum_two(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	printf("%s\n", __func__);
	a = tuple(99, 2, 20, 9);
	b = tuple(1, 3, 10, 10);
	c = tuple(100, 5, 30, 19);
	d = sum(a, b);
	assert(tuple_equal(c, d));
}
