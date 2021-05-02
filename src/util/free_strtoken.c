/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strtoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:30:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/01 17:43:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	free_strtoken(char	***tokens)
{
	int	index;

	if (tokens && *tokens)
	{
		index = 0;
		while (*(*tokens + index))
			free(*(*tokens + index++));
		free(*tokens);
	}
}
