/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:14:02 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/23 19:14:03 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int			i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			return ((unsigned char *)(dst + i + 1));
		}
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i ++;
		n --;
	}
	return (0);
}
