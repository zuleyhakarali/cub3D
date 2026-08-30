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

// duvar yüksekliğini hesaplayıp, texture'dan örnekleyerek 
// ekran buffer'ına yazma

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

static void	get_draw_bounds(t_ray *ray, int *start, int *end)
{
	int	line_height;

	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	*start = -line_height / 2 + WIN_HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = line_height / 2 + WIN_HEIGHT / 2;
	if (*end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
}

void	draw_wall_column(t_cub *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		tex_x;
	int		start;
	int		end;
	int		line_height;
	double	step;
	double	tex_pos;
	int		y;

	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	get_draw_bounds(ray, &start, &end);
	tex = select_texture(game, ray);
	tex_x = calc_tex_x(game, ray, tex);
	step = (double)tex->heig / line_height;
	tex_pos = (start - WIN_HEIGHT / 2 + line_height / 2) * step;
	y = start;
	while (y < end)
	{
		put_pixel(game, x, y, get_tex_color(tex, tex_x,
				(int)tex_pos % tex->heig));
		tex_pos += step;
		y++;
	}
}
