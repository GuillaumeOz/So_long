/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:49:06 by gozsertt          #+#    #+#             */
/*   Updated: 2021/08/07 11:03:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_H
# define SO_LONG_ERROR_H

typedef enum e_so_long_error
{
	ERROR_ENGINE1 = 2,
	ERROR_APPLICATION1,
	ERROR_COLOR1,
	ERROR_IMAGE1,
	ERROR_GHOST1,
	ERROR_GHOST2,
	ERROR_PLAYER1,
	ERROR_PLAYER2,
	ERROR_COLLECTIBLE1,
	ERROR_COLLECTIBLE2,
	ERROR_EXIT1,
	ERROR_EXIT2,
	ERROR_EXIT3,
	ERROR_ENV1,
	ERROR_ENV2,
	ERROR_ENV3,
	ERROR_PARSING1,
	ERROR_PARSING2,
	ERROR_PARSING3,
	ERROR_PARSING4,
	ERROR_PARSING5,
	ERROR_PARSING6,
	ERROR_PARSING7,
	ERROR_PARSING8,
	ERROR_PARSING9,
	ERROR_PARSING10,
	ERROR_PARSING11,
	ERROR_PARSING12,
	ERROR_PARSING13,
	ERROR_PARSING14,
	ERROR_PARSING15,
	ERROR_PARSING16,
	ERROR_PARSING17,
	ERROR_PARSING18,
	ERROR_PARSING19,
	ERROR_PARSING20,
	ERROR_PARSING21,
	ERROR_PARSING22,
}				t_so_long_error;

void	so_long_error(t_so_long_error error, char *error_msg);

#endif