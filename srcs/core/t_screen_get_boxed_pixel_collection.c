#include "minirt.h"
#include "libft.h"

void	t_screen_get_boxed_pixel_collection(t_screen *screen
								, t_screen_box *box
								, t_boxed_pixel_collection *collection)
{
	ft_memcpy(collection->min, box->ulc, sizeof(t_screen_coord));
	ft_memcpy(collection->cur, box->ulc, sizeof(t_screen_coord));
	ft_memcpy(collection->max, box->brc, sizeof(t_screen_coord));
	ft_memcpy(collection->dw, screen->dw, sizeof(t_translation));
	t_vec3_lcomb(box->ulc[height], screen->dh, screen->ulc_position
				, collection->position);
	t_vec3_lcomb(box->ulc[width], screen->dw, collection->position
				, collection->position);
	t_vec3_lcomb(box->ulc[width] - box->brc[width], screen->dw
				, screen->dh, collection->dh);
}
