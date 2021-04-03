/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:42:56 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_normalize_one(void)
{
	t_vector	a;
	t_vector	b;
	t_vector	c;

	printf("%s\n", __func__);
	a = vector(4, 0, 0);
	b = normalize(a);
	c = vector(1, 0, 0);
	assert(tuple_equal(b, c));
}

void	test_normalize_two(void)
{
	t_vector	a;
	t_vector	b;
	t_vector	c;
	double		temp;

	printf("%s\n", __func__);
	temp = sqrt(14);
	a = vector(1, 2, 3);
	b = normalize(a);
	c = vector(1 / temp, 2 / temp, 3 / temp);
	assert(tuple_equal(b, c));
}

void	test_normalize_three(void)
{
	t_vector	a;
	double		b;

	printf("%s\n", __func__);
	a = vector(1, 2, 3);
	b = length(normalize(a));
	assert(b == 1);
}
