#include "../includes/fdf.h"

int	get_pix_color(t_image *img, int x, int y)
{
	return (*(int *)(img->data + (x * img->bpp / 8 + y * img->size_line)));
}