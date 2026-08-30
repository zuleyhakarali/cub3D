/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:16:33 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 12:40:26 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	clean_mlx(t_cub *game)
{
	int	i;

	if (!game->mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->mlx->textures[i].img)
			mlx_destroy_image(game->mlx->mlx, game->mlx->textures[i].img);
		i++;
	}
	if (game->mlx->screen_b.img)
		mlx_destroy_image(game->mlx->mlx, game->mlx->screen_b.img);
	if (game->mlx->window)
		mlx_destroy_window(game->mlx->mlx, game->mlx->window);
	if (game->mlx->mlx)
	{
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
	}
	free(game->mlx);
	game->mlx = NULL;
}

void	exit_game(t_cub *game)
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
