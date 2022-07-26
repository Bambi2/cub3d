/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:37 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:37 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_ceil_floor(t_cub *cub, t_rcst rcst)
{
	int	i;
	int	ceil_color;
	int	floor_color;

	ceil_color = (cub->celling[0] << 16
			| cub->celling[1] << 8 | cub->celling[2]);
	floor_color = (cub->floor[0] << 16 | cub->floor[1] << 8 | cub->floor[2]);
	i = 0;
	while (i < rcst.draw_start)
	{
		ft_put_pixel(&(cub->mlx), rcst.i, i, ceil_color);
		i++;
	}
	i = rcst.draw_end;
	while (i < cub->win_h)
	{
		ft_put_pixel(&(cub->mlx), rcst.i, i, floor_color);
		i++;
	}
}

static void	draw_texture_ver(t_rcst rcst, t_mlx *mlx,
	t_texture *texture, int screen_height)
{
	double	tex_pos;
	int		tex_y;
	double	tex_y_step;
	int		color;

	tex_y_step = (double)texture->height / rcst.line_height;
	tex_pos = (rcst.draw_start - screen_height / 2
			+ rcst.line_height / 2) * tex_y_step;
	while (rcst.draw_start < rcst.draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += tex_y_step;
		color = get_color(texture, rcst.tex_x, tex_y);
		ft_put_pixel(mlx, rcst.i, rcst.draw_start, color);
		rcst.draw_start++;
	}
}

void	draw_texture(t_rcst rcst, t_cub *cub)
{
	int	tex_num;

	if (rcst.side == 0)
		rcst.wall_x = cub->hero_y + rcst.ray_dir_y * rcst.perp_wall_distance;
	else
		rcst.wall_x = cub->hero_x + rcst.ray_dir_x * rcst.perp_wall_distance;
	rcst.wall_x -= floor(rcst.wall_x);
	rcst.tex_x = (int)(rcst.wall_x * cub->textures[0].width);
	if (rcst.side == 1 && rcst.ray_dir_y <= 0)
		tex_num = 1;
	else if (rcst.side == 1 && rcst.ray_dir_y > 0)
		tex_num = 0;
	else if (rcst.side == 0 && rcst.ray_dir_x <= 0)
		tex_num = 3;
	else
		tex_num = 2;
	draw_ceil_floor(cub, rcst);
	draw_texture_ver(rcst, &(cub->mlx), cub->textures + tex_num, cub->win_h);
}
