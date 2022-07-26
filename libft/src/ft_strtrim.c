/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:52 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:54 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_new_start(char const *s1, char const *set, int i, int j)
{
	while (s1[i] != '\0' && set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			j = -1;
			i ++;
		}
		j ++;
	}
	return (i);
}

static int	ft_get_new_end(char const *s1, char const *set, int i, int start)
{
	int	j;

	j = 0;
	while (i > start && set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			j = -1;
			i --;
		}
		j ++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*s2;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1) - 1;
	start = ft_get_new_start(s1, set, 0, 0);
	len = ft_get_new_end(s1, set, len, start) - start;
	if (len == 0)
		len = -1;
	s2 = (char *) malloc (sizeof(char) * (len + 2));
	if (s2 == 0)
		return (0);
	ft_strlcpy(s2, s1 + start, len + 2);
	return (s2);
}
