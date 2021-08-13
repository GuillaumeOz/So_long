/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 13:21:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_engine	*malloc_engine(void)
{
	t_engine	*engine;

	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == NULL)
		so_long_error(ERROR_ENGINE1, "t_engine can't be malloc");
	*engine = create_engine();
	return (engine);
}

t_engine	create_engine(void)
{
	t_engine	engine;

	engine.app = start_application(500, 500, "so_long");
	engine.map_size_x = 0;
	engine.map_size_y = 0;
	engine.player = NULL;
	engine.exit = NULL;
	engine.collectible = NULL;
	engine.env = NULL;
	engine.ghost_red = NULL;
	engine.ghost_blue = NULL;
	engine.ghost_green = NULL;
	engine.ghost_yellow = NULL;
	engine.ghost_orange = NULL;
	engine.map = malloc_list(50);
	if (BONUS == false)
		engine.allow_charset = ft_strdup("1CEP0");
	else
		engine.allow_charset = ft_strdup("1CEP0BGORY");
	engine.bonus = NO_BONUS;
	return (engine);
}

void	destroy_engine(t_engine to_destroy)
{
	if (to_destroy.player != NULL)
		free_player(to_destroy.player);
	if (to_destroy.exit != NULL)
		free_exit(to_destroy.exit);
	if (to_destroy.collectible != NULL)
		free_collectible(to_destroy.collectible);
	if (to_destroy.env != NULL)
		free_env(to_destroy.env);
	if (to_destroy.ghost_red != NULL)
		free_ghost(to_destroy.ghost_red);
	if (to_destroy.ghost_blue != NULL)
		free_ghost(to_destroy.ghost_blue);
	if (to_destroy.ghost_green != NULL)
		free_ghost(to_destroy.ghost_green);
	if (to_destroy.ghost_yellow != NULL)
		free_ghost(to_destroy.ghost_yellow);
	if (to_destroy.ghost_orange != NULL)
		free_ghost(to_destroy.ghost_orange);
	free_list(to_destroy.map, free);
	free(to_destroy.allow_charset);
	close_application(to_destroy.app);
}

void	free_engine(t_engine *to_free)
{
	destroy_engine(*to_free);
	free(to_free);
}
