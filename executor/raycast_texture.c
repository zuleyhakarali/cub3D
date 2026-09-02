/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:53 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:17:57 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_img	*pick_texture(t_cub *game, t_ray *ray)
{
	if (!ray->hit_vertical)
	{
		if (ray->dir_y > 0)
			return (&game->mlx->textures[SO_t]);
		return (&game->mlx->textures[NO_t]);
	}
	if (ray->dir_x > 0)
		return (&game->mlx->textures[EA_t]);
	return (&game->mlx->textures[WE_t]);
}

int	texture_column(t_cub *game, t_ray *ray, t_img *tex)
{
	double	hit_pos;
	int		column;

	if (ray->hit_vertical)
		hit_pos = game->y + ray->distance * ray->dir_y;
	else
		hit_pos = game->x + ray->distance * ray->dir_x;
	hit_pos -= floor(hit_pos);
	column = (int)(hit_pos * (double)tex->wid);
	return (column);
}

int	texture_pixel(t_img *tex, int tx, int ty)
{
	char	*pixel;

	pixel = tex->pix_ptr + (ty * tex->line_l) + (tx * (tex->bits_per_pix / 8));
	return (*(int *)pixel);
}
