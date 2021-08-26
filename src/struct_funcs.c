/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:04:07 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:27:37 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

t_point	create_point(int row, int col)
{
	t_point	pt;

	pt.row = row;
	pt.col = col;
	return (pt);
}

t_square	create_square(t_point start, int side)
{
	t_square	sq;

	sq.start = start;
	sq.side = side;
	return (sq);
}

int	are_chars_equal(char c1, char c2, char c3)
{
	return (c1 == c2 || c2 == c3 || c1 == c3);
}

t_metadata	create_metadata(char *buf)
{
	t_metadata	temp;
	int			i;
	int			line_len;

	line_len = get_buf_line_len(buf, 0);
	temp.filled = buf[line_len - 1];
	temp.blocker = buf[line_len - 2];
	temp.empty = buf[line_len - 3];
	temp.rows = 0;
	temp.map = buf + line_len + 1;
	i = 0;
	while (i < line_len - 3)
	{
		if (buf[i] < '0' || buf[i] > '9')
			temp.map = 0;
		temp.rows = (temp.rows * 10) + (buf[i] - '0');
		i++;
	}
	temp.cols = get_mat_cols(temp.map);
	if (are_chars_equal(temp.filled, temp.blocker, temp.empty))
		temp.map = 0;
	return (temp);
}
