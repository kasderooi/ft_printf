/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 16:51:38 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/10/30 16:51:40 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] && i < (int)size)
		i++;
	while (src[j] && i < (int)size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < (int)size)
		dst[i] = '\0';
	return (i - j + (int)ft_strlen(src));
}
