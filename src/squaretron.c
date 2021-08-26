/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squaretron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:52:15 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:34:38 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	check_square(t_metadata *md, t_point *start, int side)
{
	int	i;
	int	j;

	i = 0;
	if (side > md -> rows - start -> row)
		return (0);
	if (side > md -> cols - start -> col)
		return (0);
	while (i < side)
	{
		j = 0;
		while (j < side)
		{
			if (md -> map[((i + start -> row) * (md -> cols + 1)) + j
					+ start -> col] == md -> blocker)
				return (0);
			j++;
		}
		i++;
	}
	return (1 + check_square(md, start, side + 1));
}

t_square	travel_map(t_metadata md)
{
	t_square	biggest_square;
	t_point		cur_pos;
	int			sq_side;

	cur_pos = create_point(0, 0);
	biggest_square = create_square(cur_pos, 0);
	while (cur_pos.row < md.rows)
	{
		cur_pos.col = 0;
		while (cur_pos.col < md.cols)
		{
			sq_side = check_square(&md, &cur_pos, 1);
			if (sq_side > biggest_square.side)
				biggest_square = create_square(cur_pos, sq_side);
			if (biggest_square.side > md.cols - cur_pos.col)
				break ;
			cur_pos.col++;
		}
		cur_pos.row++;
	}
	return (biggest_square);
}

void	paint_biggest_square(t_metadata md, t_square biggest_square)
{
	t_point	cur_pos;
	int		op1;
	int		op2;

	cur_pos = create_point(0, 0);
	while (cur_pos.row < biggest_square.side)
	{
		cur_pos.col = 0;
		while (cur_pos.col < biggest_square.side)
		{
			op1 = cur_pos.row + biggest_square.start.row;
			op2 = md.cols + 1;
			md.map[op1 * op2 + cur_pos.col + biggest_square.start.col]
				= md.filled;
			cur_pos.col++;
		}
		cur_pos.row++;
	}
}

void	print_matrix(t_metadata md)
{
	ft_putstr(md.map);
}

int	matrix_routine(t_metadata md)
{
	t_square	biggest_sq;

	biggest_sq = travel_map(md);
	if (biggest_sq.side == 0)
		return (0);
	paint_biggest_square(md, biggest_sq);
	print_matrix(md);
	return (1);
}
