/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_ghost.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:30:59 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:00:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_GHOST_H
# define SO_LONG_T_GHOST_H

typedef enum e_ghost_color
{
	RED,
	BLUE,
	GREEN,
	YELLOW,
	ORANGE,
}			t_ghost_color;

typedef struct s_ghost
{
	t_application	*app;
	t_ghost_color	color;
	char			*path;
	t_int_vector2	coord;
	int				animation;
	int				rand;
	t_int_vector2	tex_resolution;
	void			*img_ptr;
	int				*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_ghost;

t_ghost	*malloc_ghost(t_application *app,
			char *path, t_ghost_color ghost_color, t_int_vector2 coord);
t_ghost	create_ghost(t_application *app,
			char *path, t_ghost_color ghost_color, t_int_vector2 coord);
void	destroy_ghost(t_ghost to_destroy);
void	free_ghost(t_ghost *to_free);

#endif