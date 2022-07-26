/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:23 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:24 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->addr + (y * mlx->ll + x * (mlx->bpp / 8));
	*(unsigned int *)dest = color;
}

unsigned int	get_color(t_texture *texture, int x, int y)
{
	char	*dest;

	dest = texture->addr + (y * texture->ll + x * (texture->bpp / 8));
	return (*(unsigned int *)dest);
}

void	print_brick(t_mlx mlx, int x1, int y1, int color)
{
	int	x2;
	int	y2;

	x1 = x1 * 10;
	y1 = y1 * 10;
	x2 = x1 + 10;
	y2 = y1 + 10;
	while (y1 < y2)
	{
		while (x1 < x2)
		{
			ft_put_pixel(&mlx, x1, y1, color);
			x1 ++;
		}
		y1 ++;
		x1 = x2 - 10;
	}
}

void	print_hero(t_mlx mlx, float x1, float y1, int color)
{
	float	x2;
	float	y2;

	x1 = x1 * 10 + 2.5;
	y1 = y1 * 10 + 2.5;
	x2 = x1 + 5;
	y2 = y1 + 5;
	while (y1 < y2)
	{
		while (x1 < x2)
		{
			ft_put_pixel(&mlx, x1, y1, color);
			x1 += 0.1;
		}
		y1 += 0.1;
		x1 = x2 - 5;
	}
}

void	draw(t_cub *cub, t_mlx mlx)
{
	drop_ray(cub);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
}
