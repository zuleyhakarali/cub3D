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

t_img	*select_texture(t_cub *game, t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->ray_dir_y > 0)
			return (&game->mlx->textures[SO_t]);
		return (&game->mlx->textures[NO_t]);
	}
	if (ray->ray_dir_x > 0)
		return (&game->mlx->textures[EA_t]);
	return (&game->mlx->textures[WE_t]);
}

int	calc_tex_x(t_cub *game, t_ray *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->wid);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->wid - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->wid - tex_x - 1;
	return (tex_x);
}

int	get_tex_color(t_img *tex, int tx, int ty)
{
	char	*pixel;

	pixel = tex->pix_ptr + (ty * tex->line_l) + (tx * (tex->bits_per_pix / 8));
	return (*(int *)pixel);
}
