/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ghost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:59:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:50:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ghost	*malloc_ghost(t_application *app,
		char *path, t_ghost_color ghost_color, t_int_vector2 coord)
{
	t_ghost	*ghost;

	ghost = (t_ghost *)malloc(sizeof(t_ghost));
	if (ghost == NULL)
		so_long_error(ERROR_GHOST1, "t_ghost* cannot be malloc");
	*ghost = create_ghost(app, path, ghost_color, coord);
	return (ghost);
}

t_ghost	create_ghost(t_application *app,
		char *path, t_ghost_color ghost_color, t_int_vector2 coord)
{
	t_ghost			ghost;
	t_int_vector2	tex;

	ghost.app = app;
	ghost.color = ghost_color;
	ghost.path = ft_strdup(path);
	ghost.coord = coord;
	ghost.animation = 0;
	ghost.rand = 3251;
	tex = create_int_vector2(0, 0);
	ghost.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, path, &tex.x, &tex.y);
	if (ghost.img_ptr == NULL)
		so_long_error(ERROR_GHOST2,
			"mlx_xpm_file_to_image failed in create_ghost");
	ghost.tex_resolution = create_int_vector2(tex.x, tex.y);
	ghost.pixels = (int *)mlx_get_data_addr(ghost.img_ptr,
			&(ghost.bits_per_pixels), &(ghost.size_line), &(ghost.endian));
	return (ghost);
}

void	destroy_ghost(t_ghost to_destroy)
{
	free(to_destroy.path);
	mlx_destroy_image(to_destroy.app->mlx_ptr, to_destroy.img_ptr);
}

void	free_ghost(t_ghost *to_free)
{
	destroy_ghost(*to_free);
	free(to_free);
}
