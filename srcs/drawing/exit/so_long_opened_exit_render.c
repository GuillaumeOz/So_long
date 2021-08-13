/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_opened_exit_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:23:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:28:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_opened_exit_pixel(t_application *app, int x, int y,
	t_color color)
{
	t_image			*image;
	char			*tmp;

	if (x < 0 || x > app->resolution.x
		|| y < 0 || y > app->resolution.y)
		return ;
	if (color.r == 0 && color.g == 0
		&& color.b == 0 && color.a == 0)
		return ;
	image = app->image;
	tmp = image->pixels + (y * image->size_line + x
			* (image->bits_per_pixels / 8));
	tmp[RED_COMP] = color.r;
	tmp[GREEN_COMP] = color.g;
	tmp[BLUE_COMP] = color.b;
	tmp[ALPHA_COMP] = color.a;
}

static void	draw_opened_exit_texture(t_engine *engine,
	float start_x, float start_y)
{
	t_color	color;
	t_exit	*exit;
	int		index;
	int		x;
	int		y;

	y = 0;
	exit = engine->exit;
	start_x *= (engine->app->resolution.x / engine->map_size_x);
	start_y *= (engine->app->resolution.y / engine->map_size_y);
	while (y < (engine->app->resolution.y / engine->map_size_y))
	{
		x = 0;
		while (x < (engine->app->resolution.x / engine->map_size_x))
		{
			index = (exit->tex_resolution.y * y + x);
			color = int_to_color(exit->pixels_open[index]);
			put_opened_exit_pixel(engine->app,
				(int)start_x + x, (int)start_y + y, color);
			x++;
		}
		y++;
	}
}

void	opened_exit_render(t_engine *engine)
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
			if (line[x] == 'E')
				draw_opened_exit_texture(engine, x, y);
			x++;
		}
		y++;
	}
}
