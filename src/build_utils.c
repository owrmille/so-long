#include "../so_long.h"

void	build_player(t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = CHICKEN;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	// (*data)->player = img;
	(*var)->textures[0] = img;
}

void	build_collectable(t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = CHICK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	// (*data)->collectable = img;
	(*var)->textures[1] = img;
}

void	build_wall(t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = ROCK;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	// (*data)->wall = img;
	(*var)->textures[2] = img;
}

void	build_exit(t_render_v **var)
{
	static void	*img;
	char		*file;
	int			size[2];

	file = HOUSE;
	if (!img)
	{
		img = mlx_xpm_file_to_image((*var)->mlx, file, &size[0], &size[1]);
	}
	// (*data)->exit = img;
	(*var)->textures[3] = img;
}
