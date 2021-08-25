/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_headers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpozuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:28:06 by jpozuelo          #+#    #+#             */
/*   Updated: 2021/08/25 18:04:06 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HEADERS
#define ALL_HEADERS

//	Libraries
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Structs
typedef struct	s_point
{
	int	row;
	int	col;
}				t_point;

typedef struct	s_square
{
	t_point	start;
	int		side;
}				t_square;

typedef struct	s_metadata
{
	char	*map;
	char	empty;
	char	blocker;
	char	filled;
	int		cols;
	int		rows;
}				t_metadata;

// file_proc.c
int	get_file_len(int fd);
int	get_buf_line_len(char *buf, int row);
//int	get_file_line_len(int fd, int row);

// helpers.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

//	input.c
int	is_usable_char(t_point pos, t_metadata md);
int	check_matrix_chars(t_metadata md);
int	check_matrix_dimensions(t_metadata md);

//	matrix_funcs.c
int	get_mat_rows(char *buf);
int	get_mat_cols(char *buf);

//	squaretron.c
int			check_square(t_metadata *md, t_point *start, int side);
t_square	travel_map(t_metadata md);
void		paint_biggest_square(t_metadata md, t_square biggest_square);
void		paint_matrix(t_metadata md);
int			matrix_routine(t_metadata md);

//	struct_funcs.c
t_point		create_point(int row, int col);
t_square	create_square(t_point start, int side);
int			are_chars_equal(char c1, char c2, char c3);
t_metadata	create_metadata(char *buf);

//	main.c
int	get_map(char **buf, char *file_name);
int	free_map(char **buf);
int	error_control(t_metadata md);
#endif
