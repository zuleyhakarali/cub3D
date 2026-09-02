/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:38 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:23:32 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	put_pixel(t_cub *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = game->mlx->screen_b.pix_ptr + (y * game->mlx->screen_b.line_l)
		+ (x * (game->mlx->screen_b.bits_per_pix / 8));
	*(int *)dst = color;
}

static void	set_wall_bounds(t_ray *ray, t_wall *wall)
{
	if (ray->distance < 0.0001)
		ray->distance = 0.0001;
	wall->height = (int)(WIN_HEIGHT / ray->distance);
	if (wall->height > WIN_HEIGHT * 100 || wall->height < 0)
		wall->height = WIN_HEIGHT * 100;
	wall->top = -wall->height / 2 + WIN_HEIGHT / 2;
	if (wall->top < 0)
		wall->top = 0;
	wall->bottom = wall->height / 2 + WIN_HEIGHT / 2;
	if (wall->bottom >= WIN_HEIGHT)
		wall->bottom = WIN_HEIGHT - 1;
	if (wall->bottom <= wall->top)
		wall->bottom = wall->top + 1;
}

static double	texture_offset(t_wall *wall, double step)
{
	int	clipped;

	clipped = wall->top - (WIN_HEIGHT / 2 - wall->height / 2);
	return (clipped * step);
}

void	draw_wall(t_cub *game, t_ray *ray, t_wall *wall)
{
	double	step;
	double	tex_pos;
	int		y;

	set_wall_bounds(ray, wall);
	wall->tex = pick_texture(game, ray);
	wall->tex_x = texture_column(game, ray, wall->tex);
	step = (double)wall->tex->heig / wall->height;
	tex_pos = texture_offset(wall, step);
	y = wall->top;
	while (y < wall->bottom)
	{
		put_pixel(game, wall->screen_x, y, texture_pixel(wall->tex,
				wall->tex_x, (int)tex_pos % wall->tex->heig));
		tex_pos += step;
		y++;
	}
}
