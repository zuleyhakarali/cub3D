#include "../cub.h"

//mlx_init, pencere, screen buffer image

static void new_window(t_cub *game)
{
    t_mlx *mlx;

    mlx = game->mlx;
    mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, 
        WIN_HEIGHT, "cub3d");
    if (mlx->window == NULL)
        error("mlx_new_window failed", 2, game);
}

void init_screen_buffer(t_cub *game)
{
    t_mlx   *mlx;

    mlx = game->mlx;
    mlx->screen_b.heig = WIN_HEIGHT;
    mlx->screen_b.wid = WIN_WIDTH;
    mlx->screen_b.img = mlx_new_image(mlx->mlx, 
        mlx->screen_b.wid, mlx->screen_b.heig);
    if (mlx->screen_b.img == NULL)
        error("image loading failed", 2, game);
    mlx->screen_b.pix_ptr = mlx_get_data_addr(mlx->screen_b.img, &mlx->screen_b.bits_per_pix, 
    &mlx->screen_b.line_l, &mlx->screen_b.endian);
    if (mlx->screen_b.pix_ptr == NULL)
        error("the img memory could not be loaded", 2, game);
    
}

void init_mlx(t_cub *game)
{
    game->mlx = ft_calloc(1, sizeof(t_mlx));
    if (game->mlx == NULL)
        error("ft_calloc failed", 2, game);
    game->mlx->mlx = mlx_init();
    if (game->mlx->mlx == NULL)
        error("mlx initialization failed", 2, game);
    new_window(game);
    init_screen_buffer(game);
}

