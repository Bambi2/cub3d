/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <mmalphit@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:35 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 21:44:47 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	count_delta(t_rcst *rcst)
{
	if (rcst->ray_dir_x == 0)
		rcst->delta_dist_x = 1e30;
	else
		rcst->delta_dist_x = fabs(1 / rcst->ray_dir_x);
	if (rcst->ray_dir_y == 0)
		rcst->delta_dist_y = 1e30;
	else
		rcst->delta_dist_y = fabs(1 / rcst->ray_dir_y);
}

static void	count_side_distance(t_rcst *rcst, t_cub *cub)
{
	if (rcst->ray_dir_x < 0)
	{
		rcst->step_x = -1;
		rcst->side_dist_x = (cub->hero_x - rcst->map_x) * rcst->delta_dist_x;
	}
	else
	{
		rcst->step_x = 1;
		rcst->side_dist_x = (rcst->map_x + 1 - cub->hero_x)
			* rcst->delta_dist_x;
	}
	if (rcst->ray_dir_y < 0)
	{
		rcst->step_y = -1;
		rcst->side_dist_y = (cub->hero_y - rcst->map_y) * rcst->delta_dist_y;
	}
	else
	{
		rcst->step_y = 1;
		rcst->side_dist_y = (rcst->map_y + 1 - cub->hero_y)
			* rcst->delta_dist_y;
	}
}

static void	dda_alg(t_rcst *rcst, t_cub *cub)
{
	while (!rcst->hit)
	{
		if (rcst->side_dist_x < rcst->side_dist_y)
		{
			rcst->side_dist_x += rcst->delta_dist_x;
			rcst->map_x += rcst->step_x;
			rcst->side = 0;
		}
		else
		{
			rcst->side_dist_y += rcst->delta_dist_y;
			rcst->map_y += rcst->step_y;
			rcst->side = 1;
		}
		if (cub->map->lines[rcst->map_y].string[rcst->map_x] == '1')
			rcst->hit = 1;
	}
}

static void	make_calculations(t_rcst *rcst, t_cub *cub)
{
	rcst->camera_x = 2 * rcst->i / (double)cub->win_w - 1;
	rcst->ray_dir_x = cub->dir_x + cub->plane_x * rcst->camera_x;
	rcst->ray_dir_y = cub->dir_y + cub->plane_y * rcst->camera_x;
	rcst->map_x = (int)cub->hero_x;
	rcst->map_y = (int)cub->hero_y;
	count_delta(rcst);
	count_side_distance(rcst, cub);
	dda_alg(rcst, cub);
	if (rcst->side == 0)
	{
		if (rcst->side_dist_x == rcst->delta_dist_x)
			rcst->perp_wall_distance = 0.9;
		else
			rcst->perp_wall_distance = rcst->side_dist_x - rcst->delta_dist_x;
	}
	else
	{
		if (rcst->side_dist_y == rcst->delta_dist_y)
			rcst->perp_wall_distance = 0.9;
		else
			rcst->perp_wall_distance = rcst->side_dist_y - rcst->delta_dist_y;
	}
}

void	drop_ray(t_cub *cub)
{
	t_rcst	rcst;

	rcst.i = 0;
	while (rcst.i < cub->win_w)
	{
		rcst.hit = 0;
		make_calculations(&rcst, cub);
		rcst.line_height = (int)(cub->win_h / rcst.perp_wall_distance);
		rcst.draw_start = cub->win_h / 2 - rcst.line_height / 2;
		if (rcst.draw_start < 0)
			rcst.draw_start = 0;
		rcst.draw_end = cub->win_h / 2 + rcst.line_height / 2;
		if (rcst.draw_end >= cub->win_h)
			rcst.draw_end = cub->win_h - 1;
		draw_texture(rcst, cub);
		rcst.i++;
	}
}
