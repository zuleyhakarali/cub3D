/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:46 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:23:44 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	calculate_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	calculate_step_side(t_cub *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->y) * ray->delta_dist_y;
	}
}

void	init_ray(t_cub *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * ((double)x / WIN_WIDTH) - 1;
	ray->ray_dir_x = game->x_dir + game->x_plane * camera_x;
	ray->ray_dir_y = game->y_dir + game->y_plane * camera_x;
	ray->map_x = (int)game->x;
	ray->map_y = (int)game->y;
	ray->hit = 0;
	calculate_delta_dist(ray);
	calculate_step_side(game, ray);
}
