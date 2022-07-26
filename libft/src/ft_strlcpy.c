/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:11 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:12 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	int	i;

	i = 0;
	if (dst_size > 0)
	{
		while (dst_size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			dst_size --;
			i ++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
