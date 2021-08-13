/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_render.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:31:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 17:26:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_render(t_engine *engine)
{
	if (BONUS == true)
		moving_player_render_bonus(engine);
	else
		static_player_render(engine);
}
