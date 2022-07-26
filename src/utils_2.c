/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:39 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:40 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	set_color(int *val, int num, int *count, t_cub *cub)
{
	if (num == 0)
		cub->floor[*count] = *val;
	else if (num == 1)
		cub->celling[*count] = *val;
	*count += 1;
	*val = -1;
}

int	is_nl(char *str)
{
	if (*str == '\0')
		return (1);
	return (0);
}

int	set_colors_util(char *str, t_cub *cub, int num, int i)
{
	int	val;
	int	count;

	val = -1;
	count = 0;
	while (str[i] != '\0')
	{
		if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != ',') || count > 2)
			return (1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (val == -1)
				val = 0;
			val = val * 10 + (str[i] - '0');
		}
		if (str[i] == ',' || str[i + 1] == 0)
		{
			if (val > 255 || val < 0 || (str[i] == ',' && count == 2))
				return (1);
			set_color(&val, num, &count, cub);
		}
		i ++;
	}
	return (count);
}
