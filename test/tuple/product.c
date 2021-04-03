/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 11:25:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_product(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;
	t_tuple	d;

	printf("%s\n", __func__);
	a = tuple(1, .2, .0, 0);
	b = tuple(.9, 1, .1, 0);
	c = tuple(.9, .2, 0, 0);
	d = product(a, b);
	assert(tuple_equal(c, d));
}
