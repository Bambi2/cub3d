/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:33:15 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:33:18 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	ft_getlen(char *str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i ++;
	}
	if (flag == 0)
		return (i);
	else
	{
		while (str[i] && str[i] == '\n')
		{
			i++;
		}
	}
	return (i - 1);
}

char	*ft_getleftstr(char *string)
{
	int		i;
	int		len;
	char	*str;

	len = ft_getlen(string, 0);
	i = -1;
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	while (string[++ i] != '\n')
		str[i] = string[i];
	return (str);
}

char	*ft_getrightstr(char *string)
{
	int		i;
	int		len;
	char	*str;

	len = ft_getlen(string, 1);
	len ++;
	i = 0;
	str = (char *) malloc (sizeof(char) * (ft_strlen(string) - len + 1));
	if (!str)
		return (0);
	while (string[i + len])
	{
		str[i] = string[i + len];
		i ++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_getprevline(char **string, char **ret_str)
{	
	char	*right_str;

	right_str = 0;
	if (*string == 0)
		return (0);
	if (ft_strrchr(*string, '\n'))
	{
		*ret_str = ft_getleftstr(*string);
		if (*ret_str != 0)
			right_str = ft_getrightstr(*string);
		free (*string);
		return (right_str);
	}
	else
	{
		if ((*string)[0] != 0)
			ft_strjoin(ret_str, string);
		free(*string);
		return (0);
	}
}

void	ft_getline(char **buf, char **string, char **ret_str)
{
	char	*left_str;

	left_str = ft_getleftstr(*buf);
	if (left_str != 0)
		*string = ft_getrightstr(*buf);
	ft_strjoin(ret_str, &left_str);
	free(*buf);
	free(left_str);
	return ;
}
