/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:30:31 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:30:32 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i ++;
	}
	return (str);
}
