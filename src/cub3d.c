/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:21 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:22 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_initial_dir(t_cub *cub)
{
	if (cub->dir == 'W' || cub->dir == 'E')
	{
		if (cub->dir == 'W')
			cub->dir_x = -1.0;
		else
			cub->dir_x = 1.0;
		cub->dir_y = 0.0;
		cub->plane_x = 0;
		cub->plane_y = 0.66;
	}
	else if (cub->dir == 'N' || cub->dir == 'S')
	{
		if (cub->dir == 'N')
			cub->dir_y = -1.0;
		else
			cub->dir_y = 1.0;
		cub->dir_x = 0.0;
		cub->plane_x = 0.66;
		cub->plane_y = 0.0;
	}
}

void	init_textures(t_cub *cub)
{
	int	i;

	cub->textures = (t_texture *) malloc(sizeof(t_texture) * 4);
	if (!cub->textures)
		ft_exit("Error with malloc: [init_textures]\n", 2);
	i = 0;
	while (i < 4)
	{
		cub->textures[i].img = mlx_xpm_file_to_image(cub->mlx.mlx,
				cub->params[i], &(cub->textures[i].width),
				&(cub->textures[i].height));
		if (!cub->textures[i].img)
			ft_exit("Couldn't load a texture\n", 2);
		cub->textures[i].addr = mlx_get_data_addr(cub->textures[i].img,
				&(cub->textures[i].bpp),
				&(cub->textures[i].ll), &(cub->textures[i].endian));
		if (!cub->textures[i].addr)
			ft_exit("Couldn't read image address]\n", 2);
		i++;
	}
}

void	cub3d(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->win_w,
			cub->win_h, "cub3d");
	cub->mlx.image = mlx_new_image(cub->mlx.mlx, cub->win_w, cub->win_h);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.image, &(cub->mlx.bpp),
			&(cub->mlx.ll), &(cub->mlx.end));
	set_initial_dir(cub);
	init_textures(cub);
	draw(cub, cub->mlx);
	mlx_key_hook(cub->mlx.win, fkey, cub);
	mlx_hook(cub->mlx.win, 17, 0, close_window, cub);
	mlx_loop(cub->mlx.mlx);
}
