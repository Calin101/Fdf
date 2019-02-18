/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   moove.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 15:40:00 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:34:30 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_initial(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	map->vector_x = define_vector(10, 4);
	map->vector_y = define_vector(-10, 4);
	map->vector_z = define_vector(0, -5.8);
	map->img = image_infos(map);
	find_proj_point(map);
}

static void	dish_view(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	map->vector_x = define_vector(10, 0);
	map->vector_y = define_vector(0, 10);
	map->vector_z = define_vector(0, 0);
	map->img = image_infos(map);
	find_proj_point(map);
}

static void	dish(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	map->vector_x = define_vector(10, 0);
	map->vector_y = define_vector(10, 0);
	map->vector_z = define_vector(0, -5);
	map->img = image_infos(map);
	find_proj_point(map);
}

static int	close_win(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free(map->img);
	free(map);
	exit(0);
}

int			keypress(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
		change_direction(map, keycode);
	if (keycode == 24 || keycode == 27)
		zoom(map, keycode);
	if (keycode == 69 || keycode == 78)
		change_height(map, keycode);
	if (keycode == 83)
		reset_initial(map);
	if (keycode == 84)
		change_orientation(map);
	if (keycode == 85)
		change_vector(map);
	if (keycode == 86)
		dish_view(map);
	if (keycode == 87)
		dish(map);
	if (keycode == 53)
		close_win(map);
	return (0);
}
