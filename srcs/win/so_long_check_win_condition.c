/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_win_condition.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:03:47 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 19:07:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_win_condition(t_engine *engine)
{
	t_list	*map;
	char	*line;
	int		y;

	y = 0;
	map = engine->map;
	while (y < engine->map_size_y)
	{
		line = list_at(map, y);
		if (ft_ischar(line, 'C') == true)
			return (false);
		y++;
	}
	return (true);
}
