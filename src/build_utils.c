#include "../so_long.h"

void	build_player(t_game_data **data, t_render_v **var)
{
	// static void	*img;
	char		*file;
	int			size[2];

	file = CHICKEN;
	if (!(*var)->textures[0])
	{
		(*var)->textures[0] = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	(*data)->player = (*var)->textures[0];
	// if (img)
	// 	free(img);
}

void	build_collectable(t_game_data **data, t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = CHICK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	(*data)->collectable = img;
	// if (img)
	// 	free(img);
}

void	build_wall(t_game_data **data, t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = ROCK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	(*data)->wall = img;
	// if (img)
	// 	free(img);
}

void	build_exit(t_game_data **data, t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = HOUSE;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	(*data)->exit = img;
	// if (img)
	// 	free(img);
}
