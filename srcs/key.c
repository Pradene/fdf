#include "../includes/fdf.h"

int	key(int keycode, t_data *data)
{
	if (keycode == 97)
		data->offx -= 1;
	else if (keycode == 100)
		data->offx += 1;
	else if (keycode == 115)
		data->offy += 1;
	else if (keycode == 119)
		data->offy -= 1;
	if (keycode == 65307)
		quit(data);
	return (0);
}
