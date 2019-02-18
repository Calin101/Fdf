/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_infos.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/21 14:10:56 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 16:56:19 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		define_color(t_point2d src, t_point2d dest, t_point2d delta,
			t_point2d *current)
{
	if (src.x > dest.x)
		current->color = get_color((*current), src, dest, delta);
	else
		current->color = get_color((*current), dest, src, delta);
	if (src.y > dest.y)
		current->color = get_color((*current), src, dest, delta);
	else
		current->color = get_color((*current), dest, src, delta);
}

void		draw_line(t_image *image, t_point2d src, t_point2d dest)
{
	t_point2d	step;
	t_point2d	pos;
	t_point2d	current;
	int			index;
	int			k;

	index = 0;
	find_step(&step, &src, &dest);
	k = redefine_step(&step);
	while (index < k)
	{
		new_pos(&pos, src, step, index);
		current = new_point(pos.x, pos.y);
		define_color(src, dest, step, &current);
		if ((pos.x > 0 && pos.x < WIN_SIZE_X) &&
		(pos.y > 0 && pos.y < WIN_SIZE_Y))
			image->img_int[(int)pos.y * WIN_SIZE_X + (int)pos.x] =
			current.color;
		index++;
	}
}

t_point2d	define_proj(t_point3d index, t_map *map)
{
	t_point2d	proj;

	proj.x = (((index.x3d * map->vector_x.x) +
	(index.y3d * map->vector_y.x) +
	(index.z3d * map->vector_z.x * map->scale_z))
	* map->scale) + map->new_win_point.x;
	proj.y = (((index.x3d * map->vector_x.y) +
	(index.y3d * map->vector_y.y) +
	(index.z3d * map->vector_z.y * map->scale_z))
	* map->scale) + map->new_win_point.y;
	proj.color = get_point_color(index.z3d, map->max_val, -1);
	return (proj);
}

void		check_line(t_point3d index, t_map *map, t_point2d proj)
{
	t_point3d	index1;

	if (index.x3d + 1 < map->len_x)
	{
		index1 = new_point3d(index.x3d + 1, index.y3d,
		map->tab_int[(int)index.y3d][(int)index.x3d + 1]);
		draw_line(map->img, proj, define_proj(index1, map));
	}
	if (index.y3d + 1 < map->len_y)
	{
		index1 = new_point3d(index.x3d, index.y3d + 1,
		map->tab_int[(int)index.y3d + 1][(int)index.x3d]);
		draw_line(map->img, proj, define_proj(index1, map));
	}
}

void		find_proj_point(t_map *map)
{
	t_point3d	index;

	index = new_point3d(0, 0, 0);
	while (index.y3d < map->len_y)
	{
		index.x3d = 0;
		while (index.x3d < map->len_x)
		{
			index.z3d = map->tab_int[(int)index.y3d][(int)index.x3d];
			check_line(index, map, define_proj(index, map));
			index.x3d++;
		}
		index.y3d++;
	}
	mlx_put_image_to_window(map->img->img_int, map->win_ptr,
	map->img->img_ptr, 0, 0);
	print_cmd(map);
}
