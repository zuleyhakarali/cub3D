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

static void	get_draw_bounds(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_wall_column(t_cub *game, t_ray *ray, int x)
{
	t_img	*tex;
	double	step;
	double	tex_pos;
	int		y;

	get_draw_bounds(ray);
	tex = select_texture(game, ray);
	ray->tex_x = calc_tex_x(game, ray, tex);
	step = (double)tex->heig / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel(game, x, y, get_tex_color(tex, ray->tex_x,
				(int)tex_pos % tex->heig));
		tex_pos += step;
		y++;
	}
}
