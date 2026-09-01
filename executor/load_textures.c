/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:23 by zkarali           #+#    #+#             */
/*   Updated: 2026/09/01 13:17:23 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	for_img_free(t_cub *game)
{
	mlx_destroy_image(game->mlx->mlx, game->mlx->screen_b.img);
	mlx_destroy_window(game->mlx->mlx, game->mlx->window);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

static int	load_single_image(t_cub *game, char *path, t_img *tex)
{
	int	width;
	int	height;

	tex->img = mlx_xpm_file_to_image(game->mlx->mlx, path, &width, &height);
	if (tex->img == NULL)
		return (0);
	tex->wid = width;
	tex->heig = height;
	tex->pix_ptr = mlx_get_data_addr(tex->img, &tex->bits_per_pix,
			&tex->line_l, &tex->endian);
	if (tex->pix_ptr == NULL)
		return (1);
	return (2);
}

static int sec_load_images(t_cub *game)
{
	int	e;
	int	w;

	e = load_single_image(game, game->ea, &game->mlx->textures[EA_t]);
	if (e != 2)
	{
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[NO_t].img);
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[SO_t].img);
		for_img_free(game);
		return (e);
	}
	w = load_single_image(game, game->we, &game->mlx->textures[WE_t]);
	if (w != 2)
	{
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[NO_t].img);
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[SO_t].img);
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[EA_t].img);
		for_img_free(game);
		return (w);
	}
	return (2);
}

void	load_images(t_cub *game)
{
	int	n;
	int	s;
	int	i;
	
	n = load_single_image(game, game->no, &game->mlx->textures[NO_t]);
	if (n != 2)
		for_img_free(game);
	s = load_single_image(game, game->so, &game->mlx->textures[SO_t]);
	if (s != 2)
	{
		mlx_destroy_image(game->mlx->mlx, game->mlx->textures[NO_t].img);
		for_img_free(game);
	}
	i = sec_load_images(game);
	if (n == 0 || s == 0 || i == 0)
		error("Failed to load image from file.", 2, game);
	else if (n == 1 || s == 1 || i == 1)
		error("the img memory could not be loaded", 2, game);
}
