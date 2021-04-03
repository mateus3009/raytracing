/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:04:54 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:55:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_vector_one(void)
{
	t_vector	a;
	t_vector	b;

	printf("%s\n", __func__);
	a = (t_vector){.x = 1, .y = 2, .z = 3, .w = 0};
	b = vector(1, 2, 3);
	assert(tuple_equal(a, b));
}

void	test_vector_two(void)
{
	t_vector	a;
	t_vector	b;

	printf("%s\n", __func__);
	a = (t_vector){.x = 4, .y = 3, .z = 2, .w = 0};
	b = vector(4, 3, 2);
	assert(tuple_equal(a, b));
}
