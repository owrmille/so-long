#include "../so_long.h"

// int	init_window(t_game_data *data, t_render_v **v)
// {
// 	int			w_width;
// 	int			w_height;

// 	(*v)->mlx = mlx_init();
// 	if (!(*v)->mlx)
// 		return (0);
// 	w_width = data->width * TILE_WIDTH;
// 	w_height = data->height * TILE_WIDTH;
// 	(*v)->win = mlx_new_window((*v)->mlx, w_width, w_height, "Time to go home");
// 	if (!(*v)->win)
// 		return (free((*v)->mlx), 0);
// 	mlx_destroy_window((*v)->mlx, (*v)->win);
// 	mlx_destroy_display((*v)->mlx);
// 	free((*v)->mlx);
// 	free((*v));
// 	return (0);
// }


void	build_images(t_game_data **data, t_render_v **var)
{
	// build_wall(data, var);
	// build_collectable(data, var);
	// build_exit(data, var);
	build_player(data, var);
}

// void	put_image(t_game_data *data, char image_type, int pos_x, int pos_y)
// {
// 	if (image_type == '0')
// 		mlx_put_image_to_window()
// }

int on_destroy(t_render_v *var)
{
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_render_v *var)
{
	(void)var;
	ft_printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	start_game(t_game_data *data)
{
	t_render_v	*v;
	int			w_width;
	int			w_height;

	v = malloc(sizeof(t_render_v));
	if (!v)
		return (0);
	v->mlx = mlx_init();
	if (!v->mlx)
		return (0);
	w_width = data->width * TILE_WIDTH;
	w_height = data->height * TILE_WIDTH;
	v->win = mlx_new_window(v->mlx, w_width, w_height, "SO LONG: nap time!");
	if (!v->win)
		return (free(v->mlx), 0);
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	build_images(&data, &v);
	mlx_put_image_to_window(v->mlx, v->win, data->player, data->player_pos_x * TILE_WIDTH, data->player_pos_y * TILE_WIDTH);
	// mlx_loop(v->mlx);
	// mlx_loop_hook(v->mlx, )
	// if (data->exit)
	// {
	// 	free(data->exit);
	// 	data->exit = NULL;
	// }

	// mlx_loop(v->mlx);
	
	// free(v->win);
	// free(v);
	// init_window(data, &v);
	// build_figures();
	// if (v->mlx)
	// {
	// 	free(v->mlx);
	// 	v->mlx = NULL;
	// }
	// if (v)
	// {
	// 	free(v);
	// 	v = NULL;
	// }
	free(v->mlx);
	// free(v->win);
	free(v->textures[0]);
	free(v->textures);
	free(v);
	mlx_destroy_window((v)->mlx, (v)->win);
	mlx_destroy_display((v)->mlx);
	exit(0);
	return (0);
}
