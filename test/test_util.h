/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:59:14 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:12:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTIL_H
# define TESTS_UTIL_H

# include "./../src/minirt.h"
# include <assert.h>
# include <stdio.h>

typedef void	(*t_test)(void);

void			execute_tests(t_test *tests);

#endif
