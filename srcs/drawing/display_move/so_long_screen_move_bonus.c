/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_screen_move_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:41:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 19:14:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_screen_move_bonus(t_engine *engine)
{
	t_player	*player;
	char		*step_str;

	if (BONUS == true)
	{
		player = engine->player;
		step_str = ft_itoa(player->step);
		mlx_string_put(engine->app->mlx_ptr, engine->app->win_ptr,
			(engine->app->resolution.x - 20), 20, 0x00FFFF, step_str);
		free(step_str);
	}
}
