/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:08:59 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 15:04:49 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = new_map();
	map->img = image_infos(map);
	if (argc != 2 || !(ft_strstr(argv[1], ".fdf")))
		return (write(1, "Usage : ./fdf <File_name.fdf>\n", 31));
	if (parse_file(map, argv[1]) == -1)
		return (write(1, "error\n", 6));
	if (map->len_x == 0)
	{
		ft_putendl("Error empty file");
		exit(0);
	}
	find_proj_point(map);
	mlx_hook(map->win_ptr, 2, 0, keypress, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
