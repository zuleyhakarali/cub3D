/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:40:55 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:14:30 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	unwanted_char(t_cub *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->f_height - game->height;
	while (i < len)
	{
		if (game->cub[i])
		{
			if (!(ft_strncmp(game->cub[i], "F ", 2) == 0
					|| ft_strncmp(game->cub[i], "C ", 2) == 0
					|| ft_strncmp(game->cub[i], "NO ", 3) == 0
					|| ft_strncmp(game->cub[i], "SO ", 3) == 0
					|| ft_strncmp(game->cub[i], "WE ", 3) == 0
					|| ft_strncmp(game->cub[i], "EA ", 3) == 0
					|| game->cub[i][0] == '\n'))
				error("There's unwanted line in the cub.", 2, game);
		}
		i++;
	}
}

void	check_the_top(t_cub *game)
{
	char	**s1;
	char	**s2;

	check_the_texture(game);
	check_the_f_c(game);
	unwanted_char(game);
	s1 = ft_split(game->f, ',');
	s2 = ft_split(game->c, ',');
	if (!s1 || !s1[0] || !s1[1] || !s1[2] || s1[3] != NULL
		|| !s2 || !s2[0] || !s2[1] || !s2[2] || s2[3] != NULL)
	{
		for_free(s1);
		for_free(s2);
		error("You have a problem with the ceil/floor RGB.", 2, game);
	}
	check_rgb(game, s1, s2);
	for_free(s1);
	for_free(s2);
}
