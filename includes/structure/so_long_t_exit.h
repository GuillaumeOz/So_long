/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_t_exit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:32:57 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:00:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_T_EXIT_H
# define SO_LONG_T_EXIT_H

typedef struct s_exit
{
	t_application	*app;
	char			*path_closed;
	char			*path_open;
	t_int_vector2	coord;
	t_int_vector2	tex_resolution;
	void			*img_ptr_closed;
	void			*img_ptr_open;
	int				*pixels_closed;
	int				*pixels_open;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}				t_exit;

t_exit		*malloc_exit(t_application *app,
				char *path_closed, char *path_open, t_int_vector2 coord);
t_exit		create_exit(t_application *app,
				char *path_closed, char *path_open, t_int_vector2 coord);
void		destroy_exit(t_exit to_destroy);
void		free_exit(t_exit *to_free);

#endif