/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 14:27:37 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:08:44 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_vector2d	define_vector(float x, float y)
{
	t_vector2d vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_image		*image_infos(t_map *map)
{
	t_image		*image;

	if ((image = malloc(sizeof(t_image))) == NULL)
		return (NULL);
	image->img_ptr = mlx_new_image(map->mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	image->img_int = (int *)mlx_get_data_addr(image->img_ptr, &(image->bpp),
	&(image->size_line), &(image->endian));
	return (image);
}

t_map		*new_map(void)
{
	t_map	*map;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->len_y = 0;
	map->len_x = 0;
	map->scale = 1;
	map->max_val = 0;
	map->scale_z = 1.2;
	map->keycode = 0;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_SIZE_X,
	WIN_SIZE_Y, "FdF");
	map->new_win_point = new_point((WIN_SIZE_X / 4), (WIN_SIZE_Y / 4));
	map->tab_int = NULL;
	map->vector_x = define_vector(10, 4);
	map->vector_y = define_vector(-10, 4);
	map->vector_z = define_vector(0, -5.8);
	return (map);
}
