/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 14:51:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	to_display(char *filename)
{
	t_display	display;
	t_list		*canvas;

	display_init(&display);
	canvas = generate_canvas(filename, &display);
	all_canvas_to_images(canvas, &display);
	ft_lstclear(&canvas, canvas_destroy);
	display_init_window(&display);
}

static void	to_bmp(char *filename)
{
	t_display	display;
	t_list		*canvas;

	canvas = generate_canvas(filename, NULL);
	all_canvas_to_bmp(canvas);
	ft_lstclear(&canvas, canvas_destroy);
}

int	main(int argc, char **argv)
{
	t_display	display;
	t_list		*canvas;

	if (argc < 2)
		fatal("Wrong arguments\nplese, use: ./miniRT <rt_file> <--save?>");
	if (argc == 3 && ft_strcmp("--save", argv[2]))
		fatal("Did you mean --save?");
	if (argc == 3)
		to_bmp(argv[1]);
	to_display(argv[1]);
	return (0);
}
