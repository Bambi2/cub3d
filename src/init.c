/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:26 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:26 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	params_init(t_cub **cub)
{
	int	i;

	i = 0;
	(*cub)->params = (char **) malloc(sizeof(char *) * 4);
	if ((*cub)->params == 0)
	{
		free((*cub));
		ft_exit("Error with malloc [cub_init]\n", 2);
	}
	while (i < 4)
	{
		(*cub)->params[i] = 0;
		i ++;
	}
}

void	cub_init(t_cub **cub)
{
	*cub = (t_cub *) malloc(sizeof(t_cub));
	if ((*cub) == 0)
		ft_exit("Error with malloc [cub_init]\n", 2);
	(*cub)->win_w = 800;
	(*cub)->win_h = 600;
	params_init(cub);
	(*cub)->tab_map = 0;
	(*cub)->x = 0;
	(*cub)->y = 0;
	(*cub)->hero_x = -1;
	(*cub)->hero_y = -1;
	(*cub)->p_count = 0;
	(*cub)->error = 0;
}
