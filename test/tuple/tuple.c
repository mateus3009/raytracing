/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:04:54 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:11:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_tuple_one(void)
{
	t_tuple	a;
	t_tuple	b;

	printf("%s\n", __func__);
	a = (t_tuple){.x = 1, .y = 2, .z = 3, .w = 4};
	b = tuple(1, 2, 3, 4);
	assert(tuple_equal(a, b));
}

void	test_tuple_two(void)
{
	t_tuple	a;
	t_tuple	b;

	printf("%s\n", __func__);
	a = (t_tuple){.x = 4, .y = 3, .z = 2, .w = 1};
	b = tuple(4, 3, 2, 1);
	assert(tuple_equal(a, b));
}
