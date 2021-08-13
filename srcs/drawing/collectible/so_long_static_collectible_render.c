/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_static_collectible_render.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:28:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:22:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_static_collectible_pixel(t_application *app, int x, int y,
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

static void	draw_static_collectible_texture(t_engine *engine,
	float start_x, float start_y)
{
	t_color			color;
	t_collectible	*collectible;
	int				index;
	int				x;
	int				y;

	y = 0;
	collectible = engine->collectible;
	start_x *= (engine->app->resolution.x / engine->map_size_x);
	start_y *= (engine->app->resolution.y / engine->map_size_y);
	while (y < (engine->app->resolution.y / engine->map_size_y))
	{
		x = 0;
		while (x < (engine->app->resolution.x / engine->map_size_x))
		{
			index = (128 * y + x);
			color = int_to_color(collectible->pixels[index]);
			put_static_collectible_pixel(engine->app,
				(int)start_x + x, (int)start_y + y, color);
			x++;
		}
		y++;
	}
}

void	static_collectible_render(t_engine *engine)
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
			if (line[x] == 'C')
				draw_static_collectible_texture(engine, x, y);
			x++;
		}
		y++;
	}
}
