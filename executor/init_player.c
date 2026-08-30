/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:17 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:22:09 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	set_dir_no_so(t_cub *game)
{
	game->x_dir = 0;
	game->y_plane = 0;
	if (game->player == 'N')
	{
		game->y_dir = -1;
		game->x_plane = 0.66;
	}
	else
	{
		game->y_dir = 1;
		game->x_plane = -0.66;
	}
}

static void	set_dir_ea_we(t_cub *game)
{
	game->y_dir = 0;
	game->x_plane = 0;
	if (game->player == 'E')
	{
		game->x_dir = 1;
		game->y_plane = 0.66;
	}
	else
	{
		game->x_dir = -1;
		game->y_plane = -0.66;
	}
}

void	init_player_dir(t_cub *game)
{
	if (game->player == 'N' || game->player == 'S')
		set_dir_no_so(game);
	else if (game->player == 'E' || game->player == 'W')
		set_dir_ea_we(game);
	else
		error("Invalid player direction.", 2, game);
}
