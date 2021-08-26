/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:13:49 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:23:29 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	get_mat_rows(char *buf)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

int	get_mat_cols(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}
