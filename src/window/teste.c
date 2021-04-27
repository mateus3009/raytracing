/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:55:46 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/27 23:39:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

typedef struct s_destroy
{
	void *ptr;
	void *win;
}				t_destroy;


int	destroy(int key, t_destroy *data)
{
	mlx_clear_window(data->ptr, data->win);
	mlx_destroy_window(data->ptr, data->win);
	return (1);
}

void	teste()
{
	mlx_ptr	mlx_ptr;
	mlx_win	mlx_win;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		printf("Nao foi possivel inicializar o mlx");
	mlx_win = mlx_new_window(mlx_ptr, 300, 300, "teste");
	mlx_hook(mlx_win, 33, 1L << 17, destroy, &(t_destroy){.ptr = mlx_ptr, .win = mlx_win});
	//mlx_hook(mlx_win, 2, 1L << 0, destroy, &(t_destroy){.ptr = mlx_ptr, .win = mlx_win});
	mlx_loop(mlx_ptr);
}
