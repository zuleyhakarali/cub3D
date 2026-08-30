/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:08 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 11:58:26 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	check_valid_chars(t_cub *game, int i, int *p)
{
	int		j;
	char	c;

	j = 0;
	while (game->cub[i][j])
	{
		c = game->cub[i][j];
		if (c != '1' && c != '0' && c != 'N' && c != 'S'
			&& c != 'W' && c != 'E' && c != '\n' && c != ' ')
			error("There is a unwanted char in the map", 2, game);
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			(*p)++;
			game->player = game->cub[i][j];
			game->x = j + 0.5;
			game->y = (i - (game->f_height - game->height)) + 0.5;
		}
		j++;
	}
}

static void	find_height(t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub[i])
	{
		j = 0;
		while (game->cub[i][j] && game->cub[i][j] == ' ')
			j++;
		if (game->cub[i][j] == '1' || game->cub[i][j] == '0'
			|| game->cub[i][j] == ' ')
		{
			while (game->cub[i])
			{
				i++;
				game->height++;
			}
			break ;
		}
		i++;
	}
}

void	is_cub_valid(t_cub *game)
{
	int	i;
	int	len;
	int	p;

	p = 0;
	find_height(game);
	check_the_top(game);
	len = game->f_height - 1;
	//if (game->cub[len][ft_strlen(game->cub[len]) - 1] == '\n')
	//	error("There is a newline in the bottom of the map.", 2, game);
	i = game->f_height - game->height;
	while (game->cub[i])
	{
		check_valid_chars(game, i, &p);
		i++;
	}
	if (p != 1)
		error("There's more or less player than wanted", 2, game);
	flood(game);
	sec_flood(game);
}
