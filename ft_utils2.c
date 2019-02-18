/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:06:42 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:35:24 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point2d	new_point(float x, float y)
{
	t_point2d	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_index		new_index(int i, int j)
{
	t_index	index;

	index.i = i;
	index.j = j;
	return (index);
}

t_point3d	new_point3d(int x, int y, int z)
{
	t_point3d	point;

	point.x3d = x;
	point.y3d = y;
	point.z3d = z;
	return (point);
}

void		print_cmd(t_map *map)
{
	t_point2d	point;
	char		*tab[7];
	int			i;

	i = -1;
	tab[0] = "A : Moove Left";
	tab[1] = "D : Moove Right";
	tab[2] = "W : Moove Up";
	tab[3] = "S : Moove Down";
	tab[4] = "+ / - : Change Scale Z";
	tab[5] = "1 / 2 / 3 / 4 / 5 : Change Views";
	tab[6] = "Echap : Quit";
	point = new_point(WIN_SIZE_X / 1.3, WIN_SIZE_Y / 1.4);
	mlx_string_put(map->mlx_ptr, map->win_ptr, point.x + 50, point.y,
	0xfffff00, "[Commands] :");
	while (++i <= 6)
		mlx_string_put(map->mlx_ptr, map->win_ptr, point.x, point.y += 25,
		0xffffff, tab[i]);
}
