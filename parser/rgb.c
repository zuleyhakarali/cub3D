/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:10:45 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:16:09 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check_sec_rgb(t_cub *game, char **s1, char **s2)
{
	int	fir;
	int	sec;
	int	thi;

	fir = ft_atoi(s2[0]);
	sec = ft_atoi(s2[1]);
	thi = ft_atoi(s2[2]);
	if ((fir > 255 || fir < 0) || (sec > 255 || sec < 0)
		|| (thi > 255 || thi < 0))
	{
		for_free(s1);
		for_free(s2);
		error("Ceiling's RGB values are incorrect.", 2, game);
	}
	game->ceil = (fir << 16) | (sec << 8) | thi;
}

void	check_rgb(t_cub *game, char **s1, char **s2)
{
	int	fir;
	int	sec;
	int	thi;

	is_int(s1, s2, game);
	fir = ft_atoi(s1[0]);
	sec = ft_atoi(s1[1]);
	thi = ft_atoi(s1[2]);
	if ((fir > 255 || fir < 0) || (sec > 255 || sec < 0)
		|| (thi > 255 || thi < 0))
	{
		for_free(s1);
		for_free(s2);
		error("Floor's RGB values are incorrect.", 2, game);
	}
	game->floor = (fir << 16) | (sec << 8) | thi;
	check_sec_rgb(game, s1, s2);
}
