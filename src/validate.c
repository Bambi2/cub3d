/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:43 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:44 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_left(t_map *map, int i, int j)
{
	int	mark;

	mark = 0;
	while (j >= 0 && mark == 0)
	{
		if (map->lines[i].string[j] == '1')
			mark = 1;
		if (map->lines[i].string[j] == ' ')
			break ;
		j --;
	}
	if (mark == 0)
		return (0);
	return (1);
}

static int	check_right(t_map *map, int i, int j)
{
	int	mark;

	mark = 0;
	while (j < map->lines[i].len && mark == 0)
	{
		if (map->lines[i].string[j] == '1')
			mark = 1;
		if (map->lines[i].string[j] == ' ')
			break ;
		j ++;
	}
	if (mark == 0)
		return (0);
	return (1);
}

static int	check_up(t_map *map, int i, int j)
{
	int	mark;

	mark = 0;
	while (i >= 0 && mark == 0)
	{
		if (map->lines[i].string[j] == '1')
			mark = 1;
		if (map->lines[i].string[j] == ' ')
			break ;
		i --;
	}
	if (mark == 0)
		return (0);
	return (1);
}

static int	check_down(t_map *map, int i, int j)
{
	int	mark;

	mark = 0;
	while (i < map->count_of_string && mark == 0)
	{
		if (map->lines[i].string[j] == '1')
			mark = 1;
		if (map->lines[i].string[j] == ' ')
			break ;
		i ++;
	}
	if (mark == 0)
		return (0);
	return (1);
}

int	check_elems(t_map *map, int i, int j)
{
	if (check_right(map, i, j) == 0)
		return (0);
	if (check_left(map, i, j) == 0)
		return (0);
	if (check_down(map, i, j) == 0)
		return (0);
	if (check_up(map, i, j) == 0)
		return (0);
	return (1);
}
