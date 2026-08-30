/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:41:26 by zkarali           #+#    #+#             */
/*   Updated: 2026/08/30 16:19:14 by zkarali          ###   ########.fr       */
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
