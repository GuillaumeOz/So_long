/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_collectible_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:02:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/05 16:39:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_render(t_engine *engine)
{
	if (BONUS == true)
		moving_collectible_render_bonus(engine);
	else
		static_collectible_render(engine);
}
