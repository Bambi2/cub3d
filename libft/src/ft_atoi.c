/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:00:58 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:01:00 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_is_space(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\n')
		*i = *i + 1;
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	val;
	long int	a;

	i = 0;
	val = 0;
	a = 1;
	ft_is_space(str, &i);
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			a = -1;
		i ++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10;
		val = val + (str[i] - '0');
		if (val * a < -2147483648)
			return (0);
		if (val * a > 2147483647)
			return (-1);
		i ++;
	}
	return (val * a);
}
