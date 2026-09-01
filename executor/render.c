/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:18:00 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:18:05 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

#include "../cub.h"

void	draw_floor_ceil(t_cub *game)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			dst = game->mlx->screen_b.pix_ptr + (y * game->mlx->screen_b.line_l)
				+ (x * (game->mlx->screen_b.bits_per_pix / 8));
			if (y < WIN_HEIGHT / 2)
				*(int *)dst = game->ceil;
			else
				*(int *)dst = game->floor;
			x++;
		}
		y++;
	}
}

void	render_frame(t_cub *game)
{
	t_ray	ray;
	t_wall	wall;

	draw_floor_ceil(game);
	wall.screen_x = 0;
	while (wall.screen_x < WIN_WIDTH)
	{
		init_ray(game, &ray, wall.screen_x);
		cast_ray(game, &ray);
		draw_wall(game, &ray, &wall);
		wall.screen_x++;
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->window,
		game->mlx->screen_b.img, 0, 0);
}

int	game_loop(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	move_player(game);
	rotate_player(game);
	render_frame(game);
	return (0);
}
