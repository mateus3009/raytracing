/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 22:21:19 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_display	display;
	t_list		*canvas;

	if (argc < 2 || (argc == 3 && ft_strcmp("--save", argv[2])))
		fatal("Wrong arguments\n./miniRT <rt_file> <--save?>");
	if (argc == 2)
		canvas = generate_canvas(argv[1], &display);
	else
		canvas = generate_canvas(argv[1], NULL);
	all_canvas_to_bmp(canvas);
	ft_lstclear(&canvas, canvas_destroy);
	return (0);
}
