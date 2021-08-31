/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:32:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/08/31 17:45:20 by sergiodg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all_headers.h"

int	free_map(char **buf)
{
	if (*buf)
		free(*buf);
	if (!*buf)
		return (1);
	else
		return (0);
}

int	verif_input(int argc, char *argv, char **buf, t_metadata *md)
{
	int	comp;

	comp = 0;
	if (argc == 1)
		comp += get_map_stdin(buf);
	else
		comp += get_map(buf, argv);
	*md = create_metadata(*buf);
	if (*(md -> map) != '\0')
		comp++;
	comp += error_control(*md);
	return (comp);
}

int	main(int argc, char **argv)
{
	t_metadata	md;
	char		*buf;
	int			i;
	int			comp;

	if (argc == 1)
		i = 0;
	else
		i = 1;
	while (i < argc)
	{
		comp = verif_input(argc, argv[i], &buf, &md);
		if (comp == 3)
			comp += matrix_routine(md);
		if (comp == 4 && i != argc - 1)
			ft_putstr("\n");
		if (comp != 4)
			ft_putstr("Map error\n");
		free_map(&buf);
		i++;
	}
	return (0);
}
