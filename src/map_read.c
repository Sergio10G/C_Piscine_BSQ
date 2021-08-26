/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:40:37 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/26 13:32:00 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	get_map(char **buf, char *file_name)
{
	int		fd;
	int		len;
	char	*buf_tmp;
	int		read_chars;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	len = get_file_len(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	buf_tmp = malloc((len + 1) * sizeof(char));
	if (!buf_tmp)
		return (0);
	read_chars = read(fd, buf_tmp, len);
	if (read_chars == 0)
		return (0);
	if (buf_tmp == '\0')
		return (0);
	buf_tmp[len] = '\0';
	*buf = buf_tmp;
	close(fd);
	return (1);
}

char	*stdin_read(int *len_out)
{
	int		len;
	int		new_len;
	char	*buf_temp_2;
	char	buf[8192];
	int		i;

	len = 0;
	new_len = 1;
	buf_temp_2 = malloc(1048576 * sizeof(char));
	if (!buf_temp_2)
		return (0);
	while (new_len > 0)
	{
		new_len = read(0, buf, 8192);
		i = 0;
		while (i < new_len)
		{
			buf_temp_2[i + len] = buf[i];
			i++;
		}
		len += new_len;
	}
	*len_out = len;
	return (buf_temp_2);
}

int	get_map_stdin(char **buf)
{
	int		len;
	char	*buf_tmp_2;
	char	*buf_tmp;
	int		i;

	buf_tmp_2 = stdin_read(&len);
	if (!buf_tmp_2)
		return (0);
	buf_tmp = malloc(((unsigned int) len + 1) * sizeof(char));
	if (!buf_tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		buf_tmp[i] = buf_tmp_2[i];
		i++;
	}
	if (buf_tmp == '\0')
		return (0);
	if (buf_tmp_2)
		free(buf_tmp_2);
	buf_tmp[len] = '\0';
	*buf = buf_tmp;
	return (1);
}
