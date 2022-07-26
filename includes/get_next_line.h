/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdonetta <fdonetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:34:08 by fdonetta          #+#    #+#             */
/*   Updated: 2022/07/24 20:34:09 by fdonetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "../libft/libft.h"

# define BUFSIZE	1000

int		ft_getlen(char *str, int flag);
void	ft_getline(char **buf, char **string, char **ret_str);
char	*ft_getprevline(char **string, char **ret_str);
char	*ft_getrightstr(char *string);
char	*ft_getleftstr(char *string);

#endif