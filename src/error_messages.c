#include "../so_long.h"

int	map_error(t_game_data **data)
{
	ft_printf("Error\n");
	free_data(*data);
	return (0);
}

void	error_msg_1(void)
{
	ft_printf("Check that you \n"
		"- pass two arguments: an executed file and a map\n"
		"- use .ber format for a map\n- use a non-empty map\n");
}

void	error_msg_2(void)
{
	ft_printf("Check that your map is \n"
		"- rectangular \n - surrounded by walls "
		"\n- contains 1x P, 1x E and at least 1x C"
		"\n- contains only symbols 0, 1, P, E, C\n");
}

void	error_msg_3(void)
{
	ft_printf("Check that there is a possible route in the map\n");
}
