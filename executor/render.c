//frame döngüsü, floor/ceil boyama, put_image

#include "../cub.h"

void draw_floor_ceil(t_cub *game)
{
    int x;
    int y;
    char    *dst;

    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            dst = game->mlx->screen_b.pix_ptr + (y * game->mlx->screen_b.line_l)
                + (x * (game->mlx->screen_b.bits_per_pix / 8));
            if (y < WIN_HEIGHT / 2)
                *(int *)dst = game->ceil;
            else
                *(int *)dst = game->floor;
            x++;
        }
        y++;
    }
}
