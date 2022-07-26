/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:33 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:33 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	set_path(char *str, t_cub *cub, int num)
{
	int		i;
	int		j;

	i = 3;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (str[i + j] == ' ')
			return (1);
		j ++;
	}
	if (j == 0)
		return (1);
	cub->params[num] = (char *) malloc (sizeof(char) * (j + 1));
	if (cub->params[num] == 0)
		return (1);
	j = 0;
	while (str[i + j] != '\0')
	{
		cub->params[num][j] = str[i + j];
		j ++;
	}
	cub->params[num][j] = 0;
	cub->p_count ++;
	return (0);
}

int	set_colors(char *str, t_cub *cub, int num)
{
	int	count;

	count = set_colors_util(str, cub, num, 2);
	if (count == 3)
	{
		cub->p_count ++;
		return (0);
	}
	return (1);
}

int	set_params(char *str, t_cub *cub)
{
	int	error;

	if (ft_strnstr(str, "NO ", 3) != 0)
		error = set_path(str, cub, 0);
	else if (ft_strnstr(str, "SO ", 3) != 0)
		error = set_path(str, cub, 1);
	else if (ft_strnstr(str, "WE ", 3) != 0)
		error = set_path(str, cub, 2);
	else if (ft_strnstr(str, "EA ", 3) != 0)
		error = set_path(str, cub, 3);
	else if (ft_strnstr(str, "F ", 2) != 0)
		error = set_colors(str, cub, 0);
	else if (ft_strnstr(str, "C ", 2) != 0)
		error = set_colors(str, cub, 1);
	else
		return (1);
	return (error);
}

void	get_params(t_cub *cub, t_list **lst, t_list *head)
{
	int	i;

	i = 0;
	while (*lst && cub->p_count != 6)
	{
		if (!is_nl((char *)(*lst)->content))
		{
			if (set_params((char *)(*lst)->content, cub) != 0)
			{
				ft_lstclear(&head, free);
				free_params (cub->params);
				free (cub);
				ft_exit("Invalid map\n", 2);
			}
		}
		*lst = (*lst)->next;
		i ++;
	}
	while (*lst && is_nl((*lst)->content))
	{
		*lst = (*lst)->next;
		i ++;
	}
	cub->error = i;
}
