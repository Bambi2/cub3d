/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:30 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:30 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_map_size(t_cub *cub, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			count ++;
		i ++;
	}
	cub->y ++;
}

void	get_map(char *map_name, t_cub *cub)
{
	int		fd;
	char	*str;
	t_list	*tmp;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return ;
	str = get_next_line(fd);
	while (str != 0)
	{
		ft_lstadd_back(&(cub->tab_map), ft_lstnew(str));
		str = get_next_line(fd);
	}
	close(fd);
	tmp = cub->tab_map;
	get_params(cub, &tmp, cub->tab_map);
	while (tmp)
	{
		get_map_size(cub, (char *)tmp->content);
		tmp = tmp->next;
	}
}

int	check_player(char c, t_cub *cub, int i, int j)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
	{
		if (cub->hero_x >= 0 || cub->hero_y >= 0)
			return (0);
		cub->hero_y = i;
		cub->hero_x = j;
		cub->dir = c;
	}
	return (1);
}

int	check_start(t_map *map, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->count_of_string)
	{
		j = 0;
		while (j < map->lines[i].len)
		{
			if (check_player(map->lines[i].string[j], cub, i, j) == 0)
				return (0);
			if (is_valid_char(map->lines[i].string[j]) == 0)
				return (0);
			if (map->lines[i].string[j] != '1'
				&& map->lines[i].string[j] != ' ')
			{
				if (check_elems(map, i, j) == 0)
					return (0);
			}
			j ++;
		}
		i ++;
	}
	return ((cub->hero_x + 1) + ((cub->hero_y + 1)));
}
