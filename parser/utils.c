/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:26 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 12:32:06 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error(char *m, int i, t_cub *game)
{
	write(2, "Error\n", 6);
	ft_putendl_fd(m, 2);
	if (game->mlx)
		clean_mlx(game);
	if (i == 1)
	{
		free(game->cub);
		game->cub = NULL;
	}
	if (i == 2)
		for_free(game->cub);
	if (game->so)
		free(game->so);
	if (game->no)
		free(game->no);
	if (game->ea)
		free(game->ea);
	if (game->we)
		free(game->we);
	if (game->f)
		free(game->f);
	if (game->c)
		free(game->c);
	free(game);
	exit(1);
}

void	for_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*open_text(char *l)
{
	l++;
	l++;
	return (ft_strtrim(l, " \n"));
}

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

	check_int(s1, s2, game);
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
