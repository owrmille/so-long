#include "../so_long.h"

int	end_game(t_game_data **data)
{
	mlx_loop_end((*data)->mlx);
	mlx_destroy_image((*data)->mlx, (*data)->textures[0]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[1]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[2]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[3]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[4]);
	mlx_destroy_window((*data)->mlx, (*data)->win);
	mlx_destroy_display((*data)->mlx);
	if ((*data)->mlx)
	{
		free((*data)->mlx);
		(*data)->mlx = NULL;
	}
	free_data(*data);
	exit(0);
	return (0);
}
