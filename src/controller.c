/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:19 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:50 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	turn_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	if (cub->dir == 'S' || cub->dir == 'W')
		angle = -0.1;
	else
		angle = 0.1;
	cub->dir_x = cub->dir_x * cos(angle) - cub->dir_y * sin(angle);
	cub->dir_y = old_dir_x * sin(angle) + cub->dir_y * cos(angle);
	cub->plane_x = cub->plane_x * cos(angle) - cub->plane_y * sin(angle);
	cub->plane_y = old_plane_x * sin(angle) + cub->plane_y * cos(angle);
}

void	turn_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	if (cub->dir == 'S' || cub->dir == 'W')
		angle = 0.1;
	else
		angle = -0.1;
	cub->dir_x = cub->dir_x * cos(angle) - cub->dir_y * sin(angle);
	cub->dir_y = old_dir_x * sin(angle) + cub->dir_y * cos(angle);
	cub->plane_x = cub->plane_x * cos(angle) - cub->plane_y * sin(angle);
	cub->plane_y = old_plane_x * sin(angle) + cub->plane_y * cos(angle);
}

void	go_forward(t_cub *cub)
{
	int	next_x;
	int	next_y;

	next_y = (int)(cub->hero_y + cub->dir_y);
	next_x = (int)(cub->hero_x + cub->dir_x);
	if (cub->map->lines[next_y].string[next_x] != '1'
		&& cub->map->lines[(int)cub->hero_y].string[next_x] != '1'
		&& cub->map->lines[next_y].string[(int)cub->hero_x] != '1')
	{
		cub->hero_x += cub->dir_x;
		cub->hero_y += cub->dir_y;
	}
}

void	go_back(t_cub *cub)
{
	int	next_x;
	int	next_y;

	next_y = (int)(cub->hero_y - cub->dir_y);
	next_x = (int)(cub->hero_x - cub->dir_x);
	if (cub->map->lines[next_y].string[next_x] != '1'
		&& cub->map->lines[(int)cub->hero_y].string[next_x] != '1'
		&& cub->map->lines[next_y].string[(int)cub->hero_x] != '1')
	{
		cub->hero_x -= cub->dir_x;
		cub->hero_y -= cub->dir_y;
	}
}

int	fkey(int key, t_cub *cub)
{
	if (key == W_KEY)
		go_forward(cub);
	else if (key == S_KEY)
		go_back(cub);
	else if (key == A_KEY)
		turn_left(cub);
	else if (key == D_KEY)
		turn_right(cub);
	else if (key == ESC)
		exit(0);
	else if (key == LEFT_KEY)
		look_left(cub);
	else if (key == RIGHT_KEY)
		look_right(cub);
	else
		return (-1);
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.image);
	cub->mlx.image = mlx_new_image(cub->mlx.mlx, cub->win_w, cub->win_h);
	draw(cub, cub->mlx);
	return (0);
}
