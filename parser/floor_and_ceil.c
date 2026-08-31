/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:17:41 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:18:35 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_iswanted(char *s)
{
	int	i;
	int	com;

	i = 1;
	com = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] && s[i] != '\n')
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ',' && s[i] != ' ')
			return (0);
		if (s[i] == ',')
			com++;
		i++;
	}
	if (com != 2)
		return (0);
	return (1);
}

static void	check_f_c_num(t_cub *game)
{
	int	i;
	int	f;
	int	c;

	i = 0;
	f = 0;
	c = 0;
	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "F ", 2) == 0)
			f++;
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
			c++;
		i++;
	}
	if (f != 1)
		error("There's more or less floor than requirement.", 2, game);
	if (c != 1)
		error("There's more or less ceil than requirement.", 2, game);
}

void	check_the_f_c(t_cub *game)
{
	int	i;

	i = 0;
	check_f_c_num(game);
	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "F ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the floor RGB", 2, game);
			game->f = open_text(game->cub[i]);
		}
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the ceil RGB", 2, game);
			game->c = open_text(game->cub[i]);
		}
		i++;
	}
}
