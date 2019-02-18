/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 16:42:11 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 15:01:53 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

double	get_percent(int start, int end, int current)
{
	double	distance;
	double	placement;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1 : (placement / distance));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		get_color(t_point2d current, t_point2d start,
		t_point2d end, t_point2d delta)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = get_percent(start.x, end.x, current.x);
	else
		percent = get_percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xff, (end.color >> 16) & 0xff,
	percent);
	green = get_light((start.color >> 8) & 0xff, (end.color >> 8) & 0xff,
	percent);
	blue = get_light(start.color & 0xff, end.color & 0xff, percent);
	return ((red << 16) | (green << 8) | blue);
}

int		get_point_color(int curr_h, int top_h, int bot_h)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = (double)(curr_h - bot_h) / (double)(top_h - bot_h);
	red = get_light((0x1483c7 >> 16) & 0xff, (0xe8f103 >> 16) & 0xff, percent);
	green = get_light((0x1483c7 >> 8) & 0xff, (0xe8f103 >> 8) & 0xff, percent);
	blue = get_light(0x1483c7 & 0xff, 0xe8f103 & 0xff, percent);
	return ((red << 16) | (green << 8) | blue);
}
