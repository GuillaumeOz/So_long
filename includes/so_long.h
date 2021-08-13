/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:29:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 12:15:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include "libft.h"
# include "../lib/mlx/mlx.h"
# include "so_long_mlx_define.h"
# include "so_long_error.h"
# include "so_long_t_color.h"
# include "so_long_t_image.h"
# include "so_long_t_application.h"
# include "so_long_t_player.h"
# include "so_long_t_ghost.h"
# include "so_long_t_collectible.h"
# include "so_long_t_exit.h"
# include "so_long_t_env.h"
# include "so_long_t_engine.h"
# include "so_long_event_manager.h"
# include "so_long_parsing.h"
# include "so_long_drawing.h"

int	quit(void *param);
int	routine(void *param);

#endif