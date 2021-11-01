/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 18:00:26 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/11/21 18:21:43 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(s1))
	{
		res[i] = ((char)s1[i]);
		i++;
	}
	res[i] = ((char)s1[i]);
	return (res);
}
