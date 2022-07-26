/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:03:28 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:03:29 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_count_row(char const *s, char c)
{
	int	i;
	int	count_row;

	i = 0;
	count_row = 1;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i ++;
		if (s[i] != c && s[i] != '\0')
		{	
			count_row += 1;
			i ++;
		}
		while (s[i] != '\0' && s[i] != c)
			i ++;
	}
	return (count_row);
}

static int	ft_get_str_len(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	while (s[*i] != '\0' && s[*i] != c)
	{
		len ++;
		(*i)++;
	}
	return (len);
}

static char	**ft_failed_free(char **strs, int j)
{
	while (j > 0)
		free(strs[--j]);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		len;

	if (s == 0)
		return (0);
	i = 0;
	j = 0;
	len = 0;
	strs = (char **) malloc (sizeof(char *) * (ft_get_count_row(s, c)));
	if (strs == 0)
		return (0);
	while (s[i] != '\0')
	{
		len = ft_get_str_len(s, c, &i);
		if (len == 0)
			continue ;
		strs[j] = (char *) malloc (sizeof(char) * (len + 1));
		if (strs[j] == 0)
			return (ft_failed_free(strs, j));
		ft_strlcpy(strs[j ++], s + (i - len), len + 1);
	}
	strs[j] = NULL;
	return (strs);
}
