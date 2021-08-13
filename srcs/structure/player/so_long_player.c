/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:24:56 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 19:15:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*malloc_player(t_application *app,
		char *path, t_int_vector2 coord)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		so_long_error(ERROR_PLAYER1, "t_player can't be malloc");
	*player = create_player(app, path, coord);
	return (player);
}

t_player	create_player(t_application *app,
		char *path, t_int_vector2 coord)
{
	t_player		player;
	t_int_vector2	tex;

	player.app = app;
	player.path = ft_strdup(path);
	player.coord = coord;
	player.animation = 0;
	player.step = 0;
	tex = create_int_vector2(0, 0);
	player.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, path, &tex.x, &tex.y);
	if (player.img_ptr == NULL)
		so_long_error(ERROR_PLAYER2,
			"mlx_xpm_file_to_image failed in create_player");
	player.tex_resolution = create_int_vector2(tex.x, tex.y);
	player.pixels = (int *)mlx_get_data_addr(player.img_ptr,
			&(player.bits_per_pixels), &(player.size_line), &(player.endian));
	player.control = NO_CTRL;
	return (player);
}

void	destroy_player(t_player to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr);
}

void	free_player(t_player *to_free)
{
	destroy_player(*to_free);
	free(to_free);
}
