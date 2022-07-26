/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusuchkov <rusuchkov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:22 by fdonetta          #+#    #+#             */
/*   Updated: 2022/04/15 22:01:20 by rusuchkov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	if (!c)
		return (len);
	while (*c != '\0')
	{
		c ++;
		len ++;
	}
	return (len);
}
