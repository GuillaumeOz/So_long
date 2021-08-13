/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moving_player_render_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:35:15 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:25:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_moving_player_pixel(t_application *app, int x, int y,
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

static void	offset_calc(t_engine *engine, int *index, int x, int y)
{
	t_player	*player;
	float		offset;

	player = engine->player;
	offset = player->animation / 8;
	*index = (128 * y + offset * 16 + x);
	if (player->animation == 64)
		player->animation = 0;
}

static void	draw_moving_player_texture(t_engine *engine,
	float start_x, float start_y)
{
	t_color			color;
	t_player		*player;
	int				index;
	int				x;
	int				y;

	y = 0;
	player = engine->player;
	start_x *= (engine->app->resolution.x / engine->map_size_x);
	start_y *= (engine->app->resolution.y / engine->map_size_y);
	while (y < (engine->app->resolution.y / engine->map_size_y))
	{
		x = 0;
		while (x < (engine->app->resolution.x / engine->map_size_x))
		{
			offset_calc(engine, &index, x, y);
			color = int_to_color(player->pixels[index]);
			put_moving_player_pixel(engine->app,
				(int)start_x + x, (int)start_y + y, color);
			x++;
		}
		y++;
	}
	player->animation += 2;
}

void	moving_player_render_bonus(t_engine *engine)
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
			if (line[x] == 'P')
				draw_moving_player_texture(engine, x, y);
			x++;
		}
		y++;
	}
}
