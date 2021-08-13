/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:26:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 13:17:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	free_engine(engine);
	printf("The game has been closed\n");
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	resizing(t_engine *engine)
{
	int	width;
	int	height;

	width = engine->map_size_x * 16;
	height = engine->map_size_y * 16;
	resize_application(engine->app, width, height);
}

int	main(int argc, char **argv)
{
	t_engine	*engine;

	engine = malloc_engine();
	parsing(engine, argc, argv);
	resizing(engine);
	mlx_do_sync(engine->app->mlx_ptr);
	event_manager(engine);
	mlx_loop_hook(engine->app->mlx_ptr, &routine, engine);
	mlx_loop(engine->app->mlx_ptr);
	return (EXIT_SUCCESS);
}
