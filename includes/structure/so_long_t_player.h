/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_player.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:06:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/06 19:15:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_PLAYER_H
# define SO_LONG_T_PLAYER_H

typedef struct s_player
{
	t_application	*app;
	char			*path;
	t_int_vector2	coord;
	int				animation;
	int				step;
	t_uint32		control;
	t_int_vector2	tex_resolution;
	void			*img_ptr;
	int				*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_player;

t_player		*malloc_player(t_application *app,
					char *path, t_int_vector2 coord);
t_player		create_player(t_application *app,
					char *path, t_int_vector2 coord);
void			destroy_player(t_player to_destroy);
void			free_player(t_player *to_free);

#endif