/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:03:49 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:19:41 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*open_text(char *l)
{
	l++;
	l++;
	return (ft_strtrim(l, " \n"));
}

static void	check_text_nums(t_cub *game)
{
	int	i;
	int	no;
	int	so;
	int	ea;
	int	we;

	i = 0;
	no = 0;
	so = 0;
	ea = 0;
	we = 0;
	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "NO ", 3) == 0)
			no++;
		else if (ft_strncmp(game->cub[i], "SO ", 3) == 0)
			so++;
		else if (ft_strncmp(game->cub[i], "EA ", 3) == 0)
			ea++;
		else if (ft_strncmp(game->cub[i], "WE ", 3) == 0)
			we++;
		i++;
	}
	if (no != 1 || so != 1 || ea != 1 || we != 1)
		error("Textures are more or less than required.", 2, game);
}

static void	file_open(t_cub *game)
{
	game->fd = open(game->no, O_RDONLY);
	if (game->fd < 0)
		error("NO file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->so, O_RDONLY);
	if (game->fd < 0)
		error("SO file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->ea, O_RDONLY);
	if (game->fd < 0)
		error("EA file cannot open.", 2, game);
	close(game->fd);
	game->fd = open(game->we, O_RDONLY);
	if (game->fd < 0)
		error("WE file cannot open.", 2, game);
	close(game->fd);
}

void	check_the_texture(t_cub *game)
{
	int	i;

	i = 0;
	check_text_nums(game);
	while (game->cub[i])
	{
		if (ft_strncmp(game->cub[i], "NO ", 3) == 0)
			game->no = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "SO ", 3) == 0)
			game->so = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "EA ", 3) == 0)
			game->ea = open_text(game->cub[i]);
		else if (ft_strncmp(game->cub[i], "WE ", 3) == 0)
			game->we = open_text(game->cub[i]);
		i++;
	}
	if (!game->no || !game->so || !game->ea || !game->we)
		error("Direction file not found.", 2, game);
	file_open(game);
}
