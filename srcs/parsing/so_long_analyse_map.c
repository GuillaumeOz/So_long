/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_analyse_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:00:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:37:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_x(t_list *map, size_t x, size_t y)
{
	char	*valid;
	char	*line;
	size_t	tmp_x;

	if (BONUS == false)
		valid = "01CEP";
	else
		valid = "01CEPBGORY";
	line = (char *)list_at(map, y);
	tmp_x = x;
	while (line[tmp_x] != '1')
		line = (char *)list_at(map, --y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == false)
		|| (ft_ischar(valid, line[tmp_x + 1]) == false))
		return (true);
	line = (char *)list_at(map, ++y);
	while (line[tmp_x] != '1')
		line = (char *)list_at(map, ++y);
	if ((ft_ischar(valid, line[tmp_x - 1]) == false)
		|| (ft_ischar(valid, line[tmp_x + 1]) == false))
		return (true);
	return (false);
}

static	bool	check_plus(t_list *map,
	t_int_vector2 map_size, int x, int y)
{
	char	*line;
	size_t	tmp_x;

	line = (char *)list_at(map, y);
	tmp_x = x;
	while (line[--x] != '1')
		if (x == 0)
			return (true);
	while (line[++x] != '1')
		if (x == (map_size.x - 1))
			return (true);
	while (line[tmp_x] != '1')
	{
		if (y == 0)
			return (true);
		line = (char *)list_at(map, --y);
	}
	line = (char *)list_at(map, ++y);
	while (line[tmp_x] != '1')
	{
		if (y == (map_size.y - 1))
			return (true);
		line = (char *)list_at(map, ++y);
	}
	return (false);
}

static	void	check_borders(t_engine *engine, int size_x, int size_y)
{
	t_int_vector2	map_size;
	char			*charset;
	char			*line;
	int				x;
	int				y;

	y = -1;
	map_size = create_int_vector2(size_x, size_y);
	if (BONUS == false)
		charset = "0CEP";
	else
		charset = "0CEPBGORY";
	while (++y < size_y)
	{
		x = -1;
		line = (char *)list_at(engine->map, y);
		while (++x < size_x)
		{
			if (ft_ischar(charset, line[x]) == true)
				if (y == 0 || x == 0
					|| check_plus(engine->map, map_size, x, y) == true
					|| check_x(engine->map, x, y) == true)
					so_long_error(ERROR_PARSING9, "The map is invalid");
		}
	}
}

void	analyse_map(t_engine *engine)
{
	check_borders(engine, engine->map_size_x, engine->map_size_y);
	load_map_informations(engine, engine->map_size_x, engine->map_size_y);
}
