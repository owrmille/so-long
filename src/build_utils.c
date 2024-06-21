#include "../so_long.h"

void	build_player(t_game_data **data)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = CHICKEN;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*data)->mlx, file, &size[0], &size[1]);
	}
	(*data)->textures[0] = img;
}

void	build_collectable(t_game_data **data)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = CHICK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*data)->mlx, file, &size[0], &size[1]);
	}
	(*data)->textures[1] = img;
}

void	build_wall(t_game_data **data)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = ROCK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*data)->mlx, file, &size[0], &size[1]);
	}
	(*data)->textures[2] = img;
}

void	build_exit(t_game_data **data)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = HOUSE;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*data)->mlx, file, &size[0], &size[1]);
	}
	(*data)->textures[3] = img;
}

void	build_ground(t_game_data **data)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = GRASS;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*data)->mlx, file, &size[0], &size[1]);
	}
	(*data)->textures[4] = img;
}