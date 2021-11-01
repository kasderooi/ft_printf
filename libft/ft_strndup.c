/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 18:00:26 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/01 21:26:58 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*ret;
	int		i;

	if (!s1)
		return (NULL);
	ret = (char*)ft_calloc(sizeof(char), len);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len - 1 && s1[i])
	{
		ret[i] = ((char)s1[i]);
		i++;
	}
	return (ret);
}
