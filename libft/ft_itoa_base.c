/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:48:55 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/08 14:46:58 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	nbr_length_base(unsigned int nbr, int baselen)
{
	unsigned int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		i++;
		nbr /= baselen;
	}
	return (i);
}

char		*ft_itoa_base(unsigned int nbr, char *base)
{
	unsigned int		len;
	unsigned int		baselen;
	char				*ret;

	if (!base)
		return NULL;
	baselen = ft_strlen(base);
	len = nbr_length_base(nbr, baselen);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len)
	{
		ret[len - 1] = base[nbr % baselen];
		nbr /= baselen;
		len--;
	}
	return (ret);
}
