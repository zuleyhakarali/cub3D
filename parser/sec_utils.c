/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:21 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/27 17:50:01 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

int	ft_iswanted(char *s)
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

void	check_text_nums(t_cub *game)
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

void	check_int(char **s1, char **s2, t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i][j] && s1[i][j] != '\n')
		{
			if (!ft_isdigit(s1[i][j]))
				error("Floor's values are not true type.", 2, game);
			j++;
		}
		i++;
	}
	check_int_sec(s2, game);
}
