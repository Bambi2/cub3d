/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:41 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:42 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_exit(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	exit (0);
}

void	free_params(char **params)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free (params[i]);
		i ++;
	}
	free (params);
}

void	ft_freeall(t_cub *cub)
{
	int	i;

	i = 0;
	ft_lstclear(&(cub->tab_map), free);
	free (cub->map->lines);
	free (cub->map);
	free_params(cub->params);
	free (cub);
}

int	close_window(void *p)
{
	p = 0;
	exit(0);
}

int	is_valid_char(char c)
{
	if (c != '1' && c != '0' && c != 'N'
		&& c != 'W' && c != 'E' && c != 'S' && c != ' ')
		return (0);
	return (1);
}
