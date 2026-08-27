/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:32 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/27 17:58:04 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	reg_exit(t_cub *game)
{
	clean_mlx(game);
	for_free(game->cub);
	if (game->so)
		free(game->so);
	if (game->no)
		free(game->no);
	if (game->ea)
		free(game->ea);
	if (game->we)
		free(game->we);
	if (game->f)
		free(game->f);
	if (game->c)
		free(game->c);
	free(game);
	exit(0);
}

int	main(int ac, char **av)
{
	t_cub	*game;

	game = ft_calloc(1, sizeof(t_cub));
	if (!game)
		return (1);
	for_read_etc(ac, av, game);
	is_cub_valid(game);
	init_mlx(game);
	load_images(game);
	draw_floor_ceil(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->window,
		game->mlx->screen_b.img, 0, 0);
	mlx_loop(game->mlx->mlx);
	reg_exit(game);
}
