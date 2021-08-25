/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 02:51:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/25 18:03:55 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	get_file_len(int fd)
{
	int		c;
	char	b[1];

	if (fd == -1)
		return (-1);
	c = 0;
	while (read(fd, b, 1) > 0)
		c++;
	close(fd);
	return (c);
}


int	get_buf_line_len(char *buf, int row)
{
	int	i;
	int	c;
	int	r;

	i = 0;
	c = 0;
	r = 0;
	while (buf[i])
	{
		if (r < row)
		{
			if (buf[i] == '\n')
				r++;
		}
		else if (r == row)
		{
			if (buf[i] == '\n')
				break ;
			c++;
		}
		i++;
	}
	return (c);
}
