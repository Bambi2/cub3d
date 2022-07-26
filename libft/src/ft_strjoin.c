/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusuchkov <rusuchkov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:53 by fdonetta          #+#    #+#             */
/*   Updated: 2022/04/24 02:57:01 by rusuchkov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strjoin(char **s1, char **s2)
{	
	char	*str;
	
	if (*s2 == 0)
		return (0);
	str = (char *) malloc (sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, *s2, ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (*s1 != 0)
		free (*s1);
	*s1 = str;	
	return (1);
}
