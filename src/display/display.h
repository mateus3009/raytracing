/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:52:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 12:37:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "./../util/util.h"

# define KEY_ESC 65307
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_img;

typedef struct s_display
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	t_img	*imgs;
	int		img_count;
	int		img_current;
}				t_display;

int		display_expose(t_display *display);
int		display_destroy(t_display *display);
int		display_handle_key(int keynum, t_display *display);
bool	display_init(t_display	*display);
bool	display_init_window(t_display *display);

#endif
