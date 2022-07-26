/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:28 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:28 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_validpath(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i ++;
	if (path[i - 1] == 'b' && path[i - 2] == 'u' && path[i - 3] == 'c'
		&& path[i - 4] == '.')
	{
		i = open(path, O_DIRECTORY);
		if (i == -1)
			return (1);
		close (i);
	}
	ft_putstr_fd("Ошибка формата файла!\n", 2);
	return (0);
}

t_list	*skip_header(t_cub *cub)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = cub->tab_map;
	while (i < cub->error && tmp != 0)
	{
		tmp = tmp->next;
		i ++;
	}
	return (tmp);
}

void	new_parse_start(t_cub *cub)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = skip_header(cub);
	cub->map = (t_map *) malloc(sizeof(t_map));
	if (cub->map == 0)
		exit(0);
	cub->map->count_of_string = cub->y;
	cub->map->lines = (t_map_line *) malloc(sizeof(t_map_line) * cub->y);
	if (cub->map->lines == 0)
		exit(0);
	while (i < cub->y)
	{
		cub->map->lines[i].string = (char *)tmp->content;
		cub->map->lines[i].len = ft_strlen(cub->map->lines[i].string);
		tmp = tmp->next;
		i ++;
	}
	i = 0;
	if (check_start(cub->map, cub) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}	
}

void	map(char **argv, t_cub *cub)
{
	get_map(argv[1], cub);
	if (cub->tab_map == 0)
	{
		free(cub);
		ft_exit("Error with geting info from file\n", 2);
	}
	new_parse_start(cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		return (0);
	if (ft_validpath(argv[1]) == 0)
		return (0);
	cub_init(&cub);
	map(argv, cub);
	cub3d(cub);
	exit(0);
}
