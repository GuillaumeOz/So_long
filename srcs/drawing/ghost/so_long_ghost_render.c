/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ghost_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:41:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:16:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ghost_render_bonus(t_engine *engine)
{
	if (BONUS == true)
		moving_ghost_render_bonus(engine);
}
