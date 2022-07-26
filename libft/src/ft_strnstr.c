/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:38 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:39 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && len - j > 0)
		{
			j ++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		j = 0;
		i ++;
		len --;
	}
	return (0);
}
