/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:04:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 16:14:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(t_engine *engine, int argc, char **argv)
{
	int	fd;

	check_arguments(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		so_long_error(ERROR_PARSING4, "The .ber file cannot be opened");
	parse_map(engine, fd);
	close(fd);
}
