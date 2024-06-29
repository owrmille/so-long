// #include "so_long.h"

// void	print_map(t_game_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->height)
// 	{
// 		ft_printf("%s\n", data->map[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }

// void	print_difference(t_game_data *data, t_game_data *data_copy)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < data->height)
// 	{
// 		while (j < data->width)
// 		{
// 			if (data->map[i][j] != data_copy->map[i][j])
// 			{
// 				ft_printf("%c", '.');
// 			}
// 			else
// 			{
// 				ft_printf("%c", data->map[i][j]);
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// }
