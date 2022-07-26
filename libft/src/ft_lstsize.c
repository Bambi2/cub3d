/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:49:04 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/13 17:49:05 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (lst == 0)
		return (0);
	while (lst->next != 0)
	{
		size ++;
		lst = lst->next;
	}
	return (size);
}
