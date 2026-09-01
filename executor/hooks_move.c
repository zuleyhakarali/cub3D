/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:16:57 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:17:03 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	can_move(t_cub *game, double nx, double ny)
{
	int	mx;
	int	my;

	mx = (int)nx;
	my = (int)ny;
	if (my < 0 || my >= game->height || mx < 0)
		return (0);
	if (mx >= (int)ft_strlen(game->cub[game->map_offset + my]))
		return (0);
	if (game->cub[game->map_offset + my][mx] == '1'
		|| game->cub[game->map_offset + my][mx] == ' ')
		return (0);
	return (1);
}

static void	move_forward(t_cub *game, double *nx, double *ny)
{
	if (game->key_w)
	{
		*nx += game->x_dir * MOVE_SPEED;
		*ny += game->y_dir * MOVE_SPEED;
	}
	if (game->key_s)
	{
		*nx -= game->x_dir * MOVE_SPEED;
		*ny -= game->y_dir * MOVE_SPEED;
	}
}

static void	move_strafe(t_cub *game, double *nx, double *ny)
{
	if (game->key_a)
	{
		*nx += game->y_dir * MOVE_SPEED;
		*ny -= game->x_dir * MOVE_SPEED;
	}
	if (game->key_d)
	{
		*nx -= game->y_dir * MOVE_SPEED;
		*ny += game->x_dir * MOVE_SPEED;
	}
}

void	move_player(t_cub *game)
{
	double	nx;
	double	ny;

	nx = game->x;
	ny = game->y;
	move_forward(game, &nx, &ny);
	move_strafe(game, &nx, &ny);
	if (can_move(game, nx, game->y))
		game->x = nx;
	if (can_move(game, game->x, ny))
		game->y = ny;
}

void	rotate_player(t_cub *game)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	angle = 0;
	if (game->key_left)
		angle = -ROT_SPEED;
	if (game->key_right)
		angle = ROT_SPEED;
	old_dir_x = game->x_dir;
	game->x_dir = game->x_dir * cos(angle) - game->y_dir * sin(angle);
	game->y_dir = old_dir_x * sin(angle) + game->y_dir * cos(angle);
	old_plane_x = game->x_plane;
	game->x_plane = game->x_plane * cos(angle) - game->y_plane * sin(angle);
	game->y_plane = old_plane_x * sin(angle) + game->y_plane * cos(angle);
}
