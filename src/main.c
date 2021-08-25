/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:32:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/25 18:27:31 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

/*
 *
 *	QUITAR!!!!!!
 *
 * */

#include <stdio.h>

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

int	get_map_fd(char **buf, int fd)
{
	int		len;
	char	buf_tmp_2[2048];
	char	*buf_tmp;
	int		i;

	len = read(fd, buf_tmp_2, 2048);
	if (len == 0)
		return (0);
	buf_tmp = malloc((len + 1) * sizeof(char));
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
	buf_tmp[len] = '\0';
	*buf = buf_tmp;
	return (1);
}

int	free_map(char **buf)
{
	if (*buf)
		free(*buf);
	if (!*buf)
		return (1);
	else
		return (0);
}

int	error_control(t_metadata md)
{
	return (check_matrix_chars(md) && check_matrix_dimensions(md));
}


int	main(int argc, char **argv)
{
	t_metadata	md;
	char		*buf;
	int			i;
	int			comp;

	comp = 0;
	if (argc == 1)
		i = 0;
	else
		i = 1;
	while (i < argc)
	{
		comp = 0;
		if (argc == 1)
			comp += get_map_fd(&buf, 0);
		else
			comp += get_map(&buf, argv[i]);
		printf("get map: %d\n", comp);
		md = create_metadata(buf);
		if (md.map != '\0')
			comp++;
		printf("create metadata: %d\n", comp);
		if (error_control(md))
			comp++;
		printf("error control: %d\n", comp);
		if (comp == 3)
			matrix_routine(md);
		else
			ft_putstr("Map error.\n");
		free_map(&buf);
		i++;
	}
	return (0);
}
