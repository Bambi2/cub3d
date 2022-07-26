/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:45 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:47 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = 0;
	while (*s != '\0')
	{
		if (*s == (const char)c)
			tmp = s;
		s ++;
	}
	if (*s == (const char)c)
		tmp = s;
	return ((char *)tmp);
}
