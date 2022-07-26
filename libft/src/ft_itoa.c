/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:02:17 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/11 17:02:19 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_int_len(int n)
{
	int			len;
	long int	mod_n;

	len = 0;
	if (n == 0)
		return (1);
	mod_n = n;
	if (n < 0)
		mod_n *= -1;
	while (mod_n > 0)
	{
		mod_n = mod_n / 10;
		len ++;
	}
	return (len);
}

static void	ft_fill_str(char **str, int n, int len)
{
	long int	mod_n;
	int			is_minus;

	mod_n = n;
	is_minus = 0;
	if (n < 0)
	{
		mod_n *= -1;
		is_minus = 1;
		len += 1;
	}
	*(*str + (len + 1)) = '\0';
	while (len >= 0 + is_minus)
	{
		*(*str + len --) = (char)((mod_n % 10) + '0');
		mod_n = mod_n / 10;
	}
	if (is_minus)
		**str = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;

	int_len = ft_get_int_len(n);
	if (n < 0)
	{
		str = (char *) malloc (sizeof(char) * (int_len + 2));
		if (str == 0)
			return (0);
	}
	else
	{
		str = (char *) malloc (sizeof(char) * (int_len + 1));
		if (str == 0)
			return (0);
	}
	ft_fill_str(&str, n, int_len - 1);
	return (str);
}
