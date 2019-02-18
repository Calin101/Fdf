/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 14:49:37 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 13:42:40 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>

# define WIN_SIZE_X 1500
# define WIN_SIZE_Y 1500
# define ABS(x) ((x < 0) ? -x : x)

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_int;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_point2d
{
	float			x;
	float			y;
	int				color;
}					t_point2d;

typedef struct		s_index
{
	int				i;
	int				j;
}					t_index;

typedef struct		s_vector2d
{
	float			x;
	float			y;
}					t_vector2d;

typedef struct		s_point3d
{
	int				x3d;
	int				y3d;
	int				z3d;
}					t_point3d;

typedef	struct		s_map
{
	int				fd;
	int				fd2;
	int				**tab_int;
	void			*win_ptr;
	void			*mlx_ptr;
	int				max_val;
	int				len_x;
	int				len_y;
	float			scale;
	float			scale_z;
	int				keycode;
	t_image			*img;
	t_point2d		new_win_point;
	t_vector2d		vector_x;
	t_vector2d		vector_y;
	t_vector2d		vector_z;
}					t_map;

t_map				*new_map(void);
t_vector2d			define_vector(float x, float y);
t_point2d			new_point(float x, float y);
t_point3d			new_point3d(int x, int y, int z);
t_image				*image_infos(t_map *map);
t_index				new_index(int i, int j);

void				change_vector(t_map *map);
void				find_proj_point(t_map *map);
void				zoom(t_map *map, int keycode);
void				change_orientation(t_map *map);
void				change_height(t_map *map, int keycode);
void				change_direction(t_map *map, int keycode);
void				find_step(t_point2d *step, t_point2d *src, t_point2d *dest);
void				new_pos(t_point2d *pos, t_point2d src, t_point2d step,
					int i);
void				print_cmd(t_map *map);

int					redefine_step(t_point2d *step);
int					return_error(char **tmp_tab, t_map *map);
int					parse_file(t_map *map, char *file);
int					keypress(int keycode, t_map *map);
int					get_point_color(int curr_h, int top_h, int bot_h);
int					get_color(t_point2d current, t_point2d start, t_point2d end,
					t_point2d delta);

#endif
