/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 12:37:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_test	*tests;

	tests = (t_test[]){
		suite_tuple,
		suite_camera,
		NULL};
	execute_tests(tests);
	printf("\nend\n");
	return (0);
}
