/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:48:55 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/11/30 11:22:48 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_length(long nbr)
{
	unsigned int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char			*ft_uitoa(unsigned int n)
{
	int			len;
	long		nbr;
	char		*ret;

	nbr = (long)n;
	len = nbr_length(nbr);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	ret[len] = '\0';
	if (nbr == 0)
		ret[0] = '0';
	while (nbr)
	{
		len--;
		ret[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (ret);
}
