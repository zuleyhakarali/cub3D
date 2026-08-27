/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:40:55 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/27 17:52:41 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_int_sec(char **s2, t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s2[i][j] && s2[i][j] != '\n')
		{
			if (!ft_isdigit(s2[i][j]))
				error("Ceiling's values are not true type.", 2, game);
			j++;
		}
		i++;
	}
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

static void	check_the_f_c(t_cub *game)
{
	int	i;

	i = 0;
	game->f_num = 0;
	game->c_num = 0;
	check_f_c_num(game);
	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "F ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the floor RGB", 2, game);
			game->f = open_text(game->cub[i]);
			game->f_num++;
		}
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
		{
			if (!ft_iswanted(game->cub[i]))
				error("You have a problem with the ceil RGB", 2, game);
			game->c = open_text(game->cub[i]);
			game->c_num++;
		}
		i++;
	}
}

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
