/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   moove2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 13:33:31 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 15:14:37 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	change_direction(t_map *map, int keycode)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	if (keycode == 0)
		map->new_win_point.x -= 15;
	if (keycode == 2)
		map->new_win_point.x += 15;
	if (keycode == 1)
		map->new_win_point.y += 15;
	if (keycode == 13)
		map->new_win_point.y -= 15;
	map->img = image_infos(map);
	find_proj_point(map);
}

void	change_height(t_map *map, int keycode)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	if (keycode == 69)
		map->scale_z *= 1.3;
	else
		map->scale_z /= 1.3;
	map->img = image_infos(map);
	find_proj_point(map);
}

void	zoom(t_map *map, int keycode)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	if (keycode == 24)
	{
		map->scale *= 1.2;
		map->scale_z *= 1.2;
	}
	if (keycode == 27)
	{
		map->scale /= 1.2;
		map->scale_z /= 1.2;
	}
	map->img = image_infos(map);
	find_proj_point(map);
}

void	change_orientation(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	map->vector_x.x *= -1;
	map->vector_x.y *= -1;
	map->vector_y.x *= -1;
	map->vector_y.y *= -1;
	map->img = image_infos(map);
	find_proj_point(map);
}

void	change_vector(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img->img_ptr);
	free(map->img);
	map->vector_x = define_vector(10, 0);
	map->vector_y = define_vector(0, 6.8);
	map->vector_z = define_vector(0, -5.8);
	map->img = image_infos(map);
	find_proj_point(map);
}
