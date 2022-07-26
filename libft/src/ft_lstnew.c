/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:48:54 by fdonetta          #+#    #+#             */
/*   Updated: 2021/10/13 17:48:57 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_obj;

	new_obj = (t_list *) malloc (sizeof(t_list));
	if (new_obj == 0)
		return (0);
	new_obj->content = content;
	new_obj->next = 0;
	return (new_obj);
}
