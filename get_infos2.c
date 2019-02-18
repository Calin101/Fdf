/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_infos2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 13:44:18 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 15:03:02 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	new_pos(t_point2d *pos, t_point2d src, t_point2d step, int i)
{
	pos->x = src.x + i * step.x;
	pos->y = src.y + i * step.y;
}

void	find_step(t_point2d *step, t_point2d *src, t_point2d *dest)
{
	step->x = dest->x - src->x;
	step->y = dest->y - src->y;
}

int		redefine_step(t_point2d *step)
{
	t_point2d	tmp;
	int			k;

	tmp = new_point(ABS(step->x), ABS(step->y));
	if (tmp.x > tmp.y)
	{
		k = ABS(step->x);
		step->y /= ABS(step->x);
		step->x /= ABS(step->x);
	}
	else
	{
		k = ABS(step->y);
		step->x /= ABS(step->y);
		step->y /= ABS(step->y);
	}
	return (k);
}
