/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:50:21 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:06:28 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	is_usable_char(t_point pos, t_metadata md)
{
	return (md.map[(pos.row * md.cols) + pos.col] == md.blocker
		|| md.map[(pos.row * md.cols) + pos.col] == md.empty
		|| md.map[(pos.row * md.cols) + pos.col] == '\n');
}

int	check_matrix_chars(t_metadata md)
{
	t_point	cur_pos;
	int		empty_chars;

	empty_chars = 0;
	cur_pos = create_point(0, 0);
	while (cur_pos.row < md.rows)
	{
		cur_pos.col = 0;
		while (cur_pos.col < md.cols)
		{
			if (md.map[(cur_pos.row * md.cols) + cur_pos.col] == md.empty)
				empty_chars++;
			if (!is_usable_char(cur_pos, md))
				return (0);
			cur_pos.col++;
		}
		cur_pos.row++;
	}
	if (empty_chars == 0)
		return (0);
	return (1);
}

int	check_matrix_dimensions(t_metadata md)
{
	t_point	cur_pos;

	cur_pos = create_point(0, 0);
	while (cur_pos.row < md.rows)
	{
		cur_pos.col = 0;
		while (cur_pos.col < md.cols)
		{
			cur_pos.col++;
		}
		if (cur_pos.col != md.cols)
			return (0);
		cur_pos.row++;
	}
	if (cur_pos.row != md.rows)
		return (0);
	return (1);
}

int	error_control(t_metadata md)
{
	return (check_matrix_chars(md) && check_matrix_dimensions(md));
}
