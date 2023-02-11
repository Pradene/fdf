#include "../includes/fdf.h"

int	key(int keycode, t_data *data)
{
	if (keycode == 65307)
		quit(data);
	return (0);
}
