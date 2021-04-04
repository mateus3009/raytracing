/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:14:22 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:44:20 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "./../util.h"
# include "./../tuple/tuple.h"

typedef struct s_matrix
{
	char	size;
	double	values[4][4];
}				t_matrix;

t_matrix		matrix(int size);
t_matrix		matrix_multiply(t_matrix a, t_matrix b);
t_tuple			matrix_product(t_matrix a, t_tuple b);
t_matrix		matrix_transpose(t_matrix original);
void			matrix_print(t_matrix m);
t_matrix		submatrix(t_matrix original, int y, int x);
double			determinant(t_matrix matrix);
double			minor(t_matrix matrix, int y, int x);
double			cofator(t_matrix matrix, int y, int x);
t_matrix		matrix_invert(t_matrix m);

#endif
