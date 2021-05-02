/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strtoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:30:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/27 22:31:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	count_strtoken(char	**tokens)
{
	int	count;

	count = 0;
	while (tokens && *tokens++)
		count++;
	return (count);
}
