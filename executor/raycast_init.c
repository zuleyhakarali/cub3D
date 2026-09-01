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

static void	set_costs(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->cost_x = 1e30;
	else
		ray->cost_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->cost_y = 1e30;
	else
		ray->cost_y = fabs(1 / ray->dir_y);
}

static void	set_steps(t_cub *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->to_border_x = (game->x - ray->cell_x) * ray->cost_x;
	}
	else
	{
		ray->step_x = 1;
		ray->to_border_x = (ray->cell_x + 1.0 - game->x) * ray->cost_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->to_border_y = (game->y - ray->cell_y) * ray->cost_y;
	}
	else
	{
		ray->step_y = 1;
		ray->to_border_y = (ray->cell_y + 1.0 - game->y) * ray->cost_y;
	}
}

void	init_ray(t_cub *game, t_ray *ray, int screen_x)
{
	double	camera_x;

	camera_x = 2 * ((double)screen_x / WIN_WIDTH) - 1;
	ray->dir_x = game->x_dir + game->x_plane * camera_x;
	ray->dir_y = game->y_dir + game->y_plane * camera_x;
	ray->cell_x = (int)game->x;
	ray->cell_y = (int)game->y;
	ray->hit_wall = 0;
	set_costs(ray);
	set_steps(game, ray);
}
