/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:17:30 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:17:33 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	is_wall(t_cub *game, t_ray *ray)
{
	return (game->cub[game->map_offset + ray->cell_y][ray->cell_x] == '1');
}

static void	step_in_x(t_ray *ray)
{
	ray->to_border_x += ray->cost_x;
	ray->cell_x += ray->step_x;
	ray->hit_vertical = 1;
}

static void	step_in_y(t_ray *ray)
{
	ray->to_border_y += ray->cost_y;
	ray->cell_y += ray->step_y;
	ray->hit_vertical = 0;
}

void	cast_ray(t_cub *game, t_ray *ray)
{
	while (!ray->hit_wall)
	{
		if (ray->to_border_x < ray->to_border_y)
			step_in_x(ray);
		else
			step_in_y(ray);
		if (is_wall(game, ray))
			ray->hit_wall = 1;
	}
	if (ray->hit_vertical)
		ray->distance = ray->to_border_x - ray->cost_x;
	else
		ray->distance = ray->to_border_y - ray->cost_y;
}
