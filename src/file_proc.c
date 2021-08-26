/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 02:51:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:38:11 by sdiez-ga         ###   ########.fr       */
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
	int	c2;

	i = 0;
	c = 0;
	c2 = 0;
	while (buf[i])
	{
		if (c < row)
		{
			if (buf[i] == '\n')
				c++;
		}
		else if (c == row)
		{
			if (buf[i] == '\n')
				break ;
			c2++;
		}
		i++;
	}
	return (c2);
}
