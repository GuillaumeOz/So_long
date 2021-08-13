/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:12:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 19:38:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	bool	check_map_line_format(t_engine *engine, char *line)
{
	char	*content;

	content = ft_strdup(line);
	if (engine->map_size_x == 0)
		engine->map_size_x = ft_strlen(content);
	else if (engine->map_size_x != (int)ft_strlen(content))
		so_long_error(ERROR_PARSING7, "The map is invalid");
	list_push_back(engine->map, content);
	(engine->map_size_y) += 1;
	if (ft_isonlycharset(line, engine->allow_charset) == false)
		return (false);
	return (true);
}

void	parse_map(t_engine *engine, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0)
			so_long_error(ERROR_PARSING5, "There are empty line in the map");
		else if (check_map_line_format(engine, line) == false)
			so_long_error(ERROR_PARSING6, "Forbidden char detected in the map");
		free(line);
	}
	if (ft_strlen(line) == 0)
		so_long_error(ERROR_PARSING5, "There are empty line in the map");
	else if (check_map_line_format(engine, line) == false)
		so_long_error(ERROR_PARSING6, "Forbidden char detected in the map");
	free(line);
	if (engine->map_size_y < 3)
		so_long_error(ERROR_PARSING8, "The map is invalid");
	analyse_map(engine);
}
