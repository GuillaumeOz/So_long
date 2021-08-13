/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_arguments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:33:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/02 13:43:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file_name(char *file_name)
{
	size_t	i;

	i = ft_strlen(file_name);
	if (i < 5)
		so_long_error(ERROR_PARSING2, "The file name is incorrect");
	if (file_name[i - 1] != 'r'
		|| file_name[i - 2] != 'e'
		|| file_name[i - 3] != 'b'
		|| file_name[i - 4] != '.')
		so_long_error(ERROR_PARSING3, "The file name extension is incorrect");
}

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
		so_long_error(ERROR_PARSING1, "The number of arguments is incorrect");
	check_file_name(argv[1]);
}
