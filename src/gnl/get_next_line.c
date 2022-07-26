/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:33:54 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:12 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	ft_getbuf(int fd, char **buf, int *ret, int flag)
{
	if (flag == 0)
	{
		*buf = (char *)malloc((BUFSIZE + 1) * sizeof(char));
		if (!(*buf))
			return (0);
	}
	*ret = read(fd, *buf, BUFSIZE);
	(*buf)[*ret] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*ret_str;
	static char	*string;
	int			ret;

	ret_str = 0;
	string = ft_getprevline(&string, &ret_str);
	if (string != 0)
		return (ret_str);
	if (!ft_getbuf(fd, &buf, &ret, 0))
		return (NULL);
	while (ret != 0)
	{
		if (ft_strrchr(buf, '\n'))
		{
			ft_getline(&buf, &string, &ret_str);
			return (ret_str);
		}
		else
			ft_strjoin(&ret_str, &buf);
		ft_getbuf(fd, &buf, &ret, 1);
	}
	free (buf);
	return (ret_str);
}
