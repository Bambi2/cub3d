/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:15 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:16 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	look_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	if (cub->dir == 'S' || cub->dir == 'W')
		angle = M_PI / 2;
	else
		angle = -M_PI / 2;
	cub->dir_x = cub->dir_x * cos(angle) - cub->dir_y * sin(angle);
	cub->dir_y = old_dir_x * sin(angle) + cub->dir_y * cos(angle);
	cub->plane_x = cub->plane_x * cos(angle) - cub->plane_y * sin(angle);
	cub->plane_y = old_plane_x * sin(angle) + cub->plane_y * cos(angle);
}

void	look_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	if (cub->dir == 'S' || cub->dir == 'W')
		angle = -M_PI / 2;
	else
		angle = M_PI / 2;
	cub->dir_x = cub->dir_x * cos(angle) - cub->dir_y * sin(angle);
	cub->dir_y = old_dir_x * sin(angle) + cub->dir_y * cos(angle);
	cub->plane_x = cub->plane_x * cos(angle) - cub->plane_y * sin(angle);
	cub->plane_y = old_plane_x * sin(angle) + cub->plane_y * cos(angle);
}
