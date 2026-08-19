//4 texture'ı xpm'den yükleme

#include "../cub.h"

static void load_single_image(t_cub *game, char *path, t_img *tex)
{
    int     width;
    int     height;

    tex->img = mlx_xpm_file_to_image(game->mlx->mlx, path, &width, &height);
    if (!tex->img)
        error("Failed to load image from file.", 2, game);
    tex->wid = width;
    tex->heig = height;
    tex->pix_ptr = mlx_get_data_addr(tex->img, &tex->bits_per_pix, &tex->line_l, &tex->endian);
    if (tex->pix_ptr == NULL)
        error("the img memory could not be loaded", 2, game);
}

void load_images(t_cub *game)
{
    load_single_image(game, game->no, &game->mlx->textures[NO_t]);
    load_single_image(game, game->so, &game->mlx->textures[SO_t]);
    load_single_image(game, game->ea, &game->mlx->textures[EA_t]);
    load_single_image(game, game->we, &game->mlx->textures[WE_t]);
}

