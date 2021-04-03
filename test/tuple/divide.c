/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:13:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_divide(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	c;

	printf("%s\n", __func__);
	a = tuple(1, -2, 3, -4);
	b = divide(a, 2);
	c = tuple(0.5, -1, 1.5, -2);
	assert(tuple_equal(b, c));
}
