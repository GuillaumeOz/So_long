/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:49:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:18:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_wall_pixel(t_application *app, int x, int y,
	t_color color)
{
	t_image	*image;
	char	*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

static void	draw_wall_texture(t_engine *engine, float start_x, float start_y)
{
	t_color	color;
	t_env	*env;
	int		index;
	int		x;
	int		y;

	y = 0;
	env = engine->env;
	start_x *= (engine->app->resolution.x / engine->map_size_x);
	start_y *= (engine->app->resolution.y / engine->map_size_y);
	while (y < (engine->app->resolution.y / engine->map_size_y))
	{
		x = 0;
		while (x < (engine->app->resolution.x / engine->map_size_x))
		{
			index = (env->tex_resolution.y * y + x);
			color = int_to_color(env->pixels_wall[index]);
			put_wall_pixel(engine->app,
				(int)start_x + x, (int)start_y + y, color);
			x++;
		}
		y++;
	}
}

void	wall_render(t_engine *engine)
{
	t_list	*map;
	char	*line;
	int		x;
	int		y;

	y = 0;
	map = engine->map;
	while (y < engine->map_size_y)
	{
		x = 0;
		while (x < engine->map_size_x)
		{
			line = list_at(map, y);
			if (line[x] == '1')
				draw_wall_texture(engine, x, y);
			x++;
		}
		y++;
	}
}
